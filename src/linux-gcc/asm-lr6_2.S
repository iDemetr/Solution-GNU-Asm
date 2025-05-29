    .section .data
    .align 2
mask_15: .word 0x000F       # 15
mask_neg16: .word 0xFFF0    # -16 (0xFFF0 для 16 бит)

    .section .rodata
# Форматные строки для printf
print_format: .asciz "%04X %016b %u %+d \n"
prompt:       .asciz "Результат для x = 12345:\n"

    .section .text
.globl main
.globl print16
.globl ab16_asm

# Функция print16
print16:
    pushq %rbp
    movq %rsp, %rbp
    
    # Загружаем 16-битное значение из памяти
    movzwl (%rdi), %esi      # arg2: unsigned short (для %04X)
    movzwl (%rdi), %edx      # arg3: unsigned short (для %08b)
    movzwl (%rdi), %ecx      # arg4: unsigned short (для %u)
    movswl (%rdi), %r8d      # arg5: signed short (для %+d)
    
    movq $print_format, %rdi # arg1: форматная строка
    call printf
    
    popq %rbp
    ret

# Основная функция
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp           # Выделяем место для переменных
    
    # Выводим приглашение
    movq $prompt, %rdi
    call puts
    
    # Создаем и инициализируем переменную x = 12345
    movw $12345, -2(%rbp)
    
    # Вызываем ab16_asm с адресом x
    leaq -2(%rbp), %rdi
    call ab16_asm
    
    # Возвращаем 0
    xorl %eax, %eax
    leave
    ret

ab16_asm:
    push %rbp
    mov %rsp, %rbp

    sub $32, %rsp           # выделим 32 байта стека для локальных переменных

    # rdi = указатель на x
    movzwl (%rdi), %eax     # загрузить x (16 бит) в eax (обнулить старшие)
    mov %ax, %bx            # сохранить x в bx для повторного использования

    movw %bx, -32(%rbp)     # Сохраняем x для печати

    # а1) беззнаковое умножение на 2: x * 2 = x << 1 (беззнаковое)
    mov %bx, %cx
    shl $1, %cx             # умножение на 2
    movw %cx, -30(%rbp)

    # а2) знаковое умножение на 2: x * 2 = x << 1 (знаковое)
    mov %bx, %cx
    sal $1, %cx             # знаковый сдвиг влево на 1
    movw %cx, -28(%rbp)

    # а3) беззнаковое деление на 2: x / 2 = x >> 1 (беззнаковое)
    mov %bx, %cx
    shr $1, %cx
    movw %cx, -26(%rbp)

    # а4) знаковое деление на 2: x / 2 = x >> 1 (знаковое)
    movsxw %bx, %cx         # расширяем bx в cx знаково
    sar $1, %cx
    movw %cx, -24(%rbp)

    # а5) остаток от беззнакового деления на 16: x % 16 = x & 15
    mov %bx, %cx
    andw $0x000F, %cx
    movw %cx, -22(%rbp)

    # а6) округление вниз до кратного 16 (беззнаковое): x & (~15)
    mov %bx, %cx
    andw $0xFFF0, %cx
    movw %cx, -20(%rbp)

    # б1) беззнаковый сдвиг влево на 1 бит: x << 1
    # Уже сделано в а1), используем -30(%rbp)

    # б2) знаковый сдвиг влево на 1 бит: x << 1
    # Уже сделано в а2), используем -28(%rbp)

    # б3) беззнаковый сдвиг вправо на 1 бит: x >> 1
    # Уже сделано в а3), используем -26(%rbp)

    # б4) знаковый сдвиг вправо на 1 бит: x >> 1
    # Уже сделано в а4), используем -24(%rbp)

    # б5) x & 15
    # Уже сделано в а5), используем -22(%rbp)

    # б6) x & -16
    # Уже сделано в а6), используем -20(%rbp)

    # Печать результатов

    lea -32(%rbp), %rdi         # Исходное значение
    call print16

    lea -30(%rbp), %rdi         # а1
    call print16

    lea -28(%rbp), %rdi         # а2
    call print16

    lea -26(%rbp), %rdi         # а3
    call print16

    lea -24(%rbp), %rdi         # а4
    call print16

    lea -22(%rbp), %rdi         # а5
    call print16

    lea -20(%rbp), %rdi         # а6
    call print16

    leave
    ret
