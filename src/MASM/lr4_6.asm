; lr4_6.asm
; Головная программа, вызывающая func8
; Microsoft x64 calling convention (Windows)

    .data
format_res db "Returned value: %u", 10, 0

    .code
    extern func8: proc
    extern printf: proc
    public main

main PROC
    sub rsp, 72          ; теневое пространство + выравнивание + 4*8 данных стека

    ; Первые 4 параметра в регистрах
    mov rcx, 1           ; a1
    mov rdx, 2           ; a2
    mov r8, 3            ; a3
    mov r9, 4            ; a4

    ; Параметры 5-8 на стеке, слева направо
    mov dword ptr [rsp+32], 5   ; a5 (5-й параметр на стеке)
    mov dword ptr [rsp+40], 6   ; a6 (6-й параметр на стеке)
    mov dword ptr [rsp+48], 7   ; a7 (7-й параметр на стеке)
    mov dword ptr [rsp+56], 8   ; a8 (8-й параметр на стеке)

    call func8

    ; Возвращаемое значение в eax

    mov rdi, rax          ; 2-й параметр printf
    lea rcx, format_res   ; 1-й параметр printf
    call printf

    add rsp, 72
    mov eax, 0
    ret

main ENDP
end
