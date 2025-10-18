
def nen(s):
    if not s:
        return ""
    result = ""
    count = 1
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            count+=1
        else:
            if count > 1:
                result += str(count)
            result+= s[i-1]
            count =1
    if count > 1:
        result += str(count)
    result += s[-1]
    return result

def giai_nen(s):
    result = ""
    i = 0
    while i < len(s):
        if s[i].isdigit():
            count = 0
            while i< len(s) and s[i].isdigit():
                count = count * 10 + int(s[i])
                i+=1
            result += s[i]*count
        else:
            result += s[i]
            i+=1
    return result

def bien_doi(s):
    steps =[s]
    while True:
        new_s = s
        if "11" in s:
            index = s.find('11')
            new_s = s[:index] + '00' + s[index+2:]
        elif "010" in s:
            index = s.find('010')
            new_s = s[:index] + '000' +s[index+3:]
        else:
            break
        
        if new_s == s:
            break
        steps.append(new_s)
        s = new_s

    if set(s) == {'0'}:
        return steps 
    else:
        return "Khong the chuyen doi"






n = "3a2b"
print(giai_nen(n))