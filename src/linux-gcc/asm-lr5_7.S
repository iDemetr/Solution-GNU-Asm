.section .rodata
prompt:     .asciz "Введите длину массива N: "
fmt:        .asciz "%d"
result_msg: .asciz "Первые %d нечётных чисел:\n"
num_fmt:    .asciz "%d "
newline:    .asciz "\n"
error_msg:  .asciz "Ошибка: N должно быть положительным числом\n"

.section .text
.globl main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp           # Выделяем место для переменной N

    # Выводим приглашение
    movq $prompt, %rdi
    xorq %rax, %rax
    call printf

    # Считываем N
    leaq -4(%rbp), %rsi      # Указатель на переменную N в стеке
    movq $fmt, %rdi
    xorq %rax, %rax
    call scanf

    # Проверяем корректность ввода
    cmpl $0, -4(%rbp)
    jle .error

    # Выводим сообщение о результате
    movq $result_msg, %rdi
    movl -4(%rbp), %esi
    xorq %rax, %rax
    call printf

    # Генерируем и выводим нечетные числа
    xorl %ebx, %ebx          # Счетчик i = 0
    movl -4(%rbp), %r12d     # N

.generate_loop:
    cmpl %r12d, %ebx
    jge .end_loop

    # Вычисляем 2*i + 1
    leal 1(%ebx, %ebx), %esi # esi = 2*i + 1 (корректный расчет)

    # Выводим число
    movq $num_fmt, %rdi      # Первый аргумент - формат
    # %esi уже содержит число (второй аргумент)
    xorq %rax, %rax
    call printf

    incl %ebx
    jmp .generate_loop

.end_loop:
    # Выводим перевод строки
    movq $newline, %rdi
    xorq %rax, %rax
    call printf

    xorq %rax, %rax          # Возвращаем 0
    jmp .exit

.error:
    movq stderr(%rip), %rdi
    movq $error_msg, %rsi
    xorq %rax, %rax
    call fprintf
    movq $1, %rax            # Возвращаем 1

.exit:
    movq %rbp, %rsp
    popq %rbp
    ret
