.section .rodata
prompt:     .asciz "Введите 16-битное число (0-65535): "
scan_fmt:   .asciz "%hu"
result_fmt: .asciz "Исходное: %hu\nОкругление вверх: %u\nОкругление вниз: %u\n"

.section .bss
.lcomm input, 2    # 16-битная переменная для ввода

.section .text
.globl main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp         # Выравнивание стека

    # Вывод приглашения
    movq $prompt, %rdi
    xorq %rax, %rax
    call printf

    # Ввод числа
    movq $scan_fmt, %rdi
    movq $input, %rsi
    xorq %rax, %rax
    call scanf

    # Вызов fc16_asm
    movq $input, %rdi
    call fc16_asm

    # Восстановление и выход
    xorq %rax, %rax
    leave
    ret

# Функция округления
.globl fc16_asm
.type fc16_asm, @function
fc16_asm:
    pushq %rbp              # Сохраняем каллер-сейв регистры
    pushq %rbx
    pushq %r12
    
    movzwl (%rdi), %ebx     # x в ebx (сохраняемое)
    movl %ebx, %r12d        # копия x в r12d
    
    movl $31, %ecx          # D-1 = 31 (volatile регистр)
    notl %ecx               # mask = ~31
    
    andl %ecx, %r12d        # x1 = x & mask
    
    leal 31(%rbx), %eax     # x + D-1 (используем lea вместо add)
    andl %ecx, %eax         # x2 = (x + D-1) & mask
    
    # Подготовка к вызову printf
    movzwl %bx, %r8d        # исходное x (16 бит, zero-extended)
    movl %r12d, %ecx        # x1
    movl %eax, %edx         # x2
    movq $result_fmt, %rdi  # форматная строка
    xorl %eax, %eax         # 0 FP args
    call printf
    
    # Восстановление регистров
    movl %r12d, %eax        # возвращаем x1 (или x2 - по условиям задачи)
    popq %r12
    popq %rbx
    popq %rbp
    ret
    