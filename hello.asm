; build:
; nasm -f elf64 test.asm -o test.o
; gcc test.o -o test

extern rand
extern srand
extern printf
extern time

section .data
    fmt db "%d: %d", 10, 0

section .bss
    hist resd 1000     ; đủ chứa các giá trị tổng

section .text
    global main

main:
    ; srand(time(NULL))
    xor rdi, rdi
    call time
    mov rdi, rax
    call srand

    mov rcx, 1000          ; số lần lặp ngoài

outer_loop:
    push rcx

    xor rbx, rbx           ; tong = 0
    mov rcx, 50            ; lặp 50 lần

inner_loop:
    call rand
    xor rdx, rdx
    mov rsi, 9
    div rsi                ; rdx = rand % 9
    inc rdx                ; 1..9
    add rbx, rdx
    loop inner_loop

    ; hist[tong]++
    mov rax, rbx
    mov rdx, 4
    mul rdx
    mov rdi, hist
    add rdi, rax
    inc dword [rdi]

    pop rcx
    loop outer_loop

    ; in kết quả
    mov rcx, 1000
    xor rbx, rbx

print_loop:
    mov eax, [hist + rbx*4]
    cmp eax, 0
    je skip

    mov rdi, fmt
    mov rsi, rbx
    mov rdx, rax
    xor rax, rax
    call printf

skip:
    inc rbx
    loop print_loop

    ret