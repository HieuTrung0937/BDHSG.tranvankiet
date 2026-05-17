import docx
import re
import json
import os

def extract_quiz(docx_path):
    if not os.path.exists(docx_path):
        print(f"Lỗi: Không tìm thấy file {docx_path}")
        return

    doc = docx.Document(docx_path)
    full_text = [para.text.strip() for para in doc.paragraphs if para.text.strip()]
    combined_text = "\n".join(full_text)

    # --- BƯỚC 1: QUÉT TẤT CẢ CÁC KIỂU ĐÁP ÁN ---
    ans_map = {} # Lưu đáp án MCQ (số) hoặc Short (số/chữ) hoặc TF (mảng)
    types_map = {} # Lưu loại câu hỏi để định hình cấu trúc

    # 1.1 Quét MCQ (1A, 2.B, 3: C...)
    mcq_matches = re.findall(r'(\d+)[\.\s\:]*([A-D])(?![ĐS])', combined_text)
    for num, char in mcq_matches:
        ans_map[int(num)] = ord(char.upper()) - ord('A')
        types_map[int(num)] = "mcq"

    # 1.2 Quét Đúng/Sai (15. ĐSSĐ hoặc 15. Đ S S Đ)
    tf_matches = re.findall(r'(\d+)[\.\s\:]*([ĐS\s]{4,})', combined_text)
    for num, chain in tf_matches:
        chain = chain.replace(" ", "").upper()
        if len(chain) >= 4:
            ans_map[int(num)] = [i for i, char in enumerate(chain[:4]) if char == 'Đ']
            types_map[int(num)] = "truefalse"

    # 1.3 Quét Trả lời ngắn (Ví dụ: Ans 20: 12.5 hoặc Đáp án 20. 150)
    # Tìm các số đứng độc lập hoặc sau từ khóa "Đáp án/Ans"
    short_matches = re.findall(r'(?:Đáp án|Ans|Câu)\s*(\d+)[\.\s\:]+([\d\.]+)(?!\s*[A-DĐS])', combined_text)
    for num, val in short_matches:
        try:
            # Chuyển sang số thực nếu có dấu chấm, nếu không để số nguyên
            ans_map[int(num)] = float(val) if '.' in val else int(val)
            types_map[int(num)] = "short"
        except:
            continue

    # --- BƯỚC 2: TÁCH VÀ DỰNG CẤU TRÚC JS ---
    questions = []
    blocks = re.split(r'(?:Question|Câu)\s+(\d+)[\.\:\s]+', combined_text, flags=re.IGNORECASE)
    
    for i in range(1, len(blocks), 2):
        q_num = int(blocks[i])
        q_full_content = blocks[i+1]
        
        # Tách text và options
        options_raw = re.findall(r'[A-D][\.\)\s]+(.*?)(?=\s+[A-D][\.\)\s]|$)', q_full_content, re.DOTALL)
        options = [f"{chr(65+idx)}. {opt.strip()}" for idx, opt in enumerate(options_raw[:4])]
        
        # Lấy text câu hỏi (bỏ phần options đi)
        q_text = re.split(r'\s+[A-D][\.\)\s]+', q_full_content)[0].strip().replace('\n', ' ')

        # Xác định type dựa trên ans_map đã quét
        q_type = types_map.get(q_num, "mcq") # Mặc định là mcq nếu ko thấy map
        
        item = {
            "type": q_type,
            "q": q_text,
        }

        if q_type == "short":
            item["answer"] = ans_map.get(q_num, 0)
        elif q_type == "truefalse":
            item["options"] = options if len(options) == 4 else ["A. Đúng", "B. Sai", "C. Sai", "D. Đúng"]
            item["answer"] = ans_map.get(q_num, [])
        else: # MCQ
            item["options"] = options
            item["answer"] = ans_map.get(q_num, 0)

        questions.append(item)

    # --- BƯỚC 3: XUẤT FILE ---
    output_filename = "quiz_data.js"
    with open(output_filename, "w", encoding="utf-8") as f:
        f.write("window.question = " + json.dumps(questions, indent=2, ensure_ascii=False) + ";")
    
    print(f"Thành công! Đã tạo file với {len(questions)} câu hỏi đủ 3 định dạng.")

if __name__ == "__main__":
    current_dir = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(current_dir, "test.docx")

    extract_quiz(file_path)