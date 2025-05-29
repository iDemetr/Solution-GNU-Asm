# file: lr4_4.S
# Программа с пятью локальными переменными, вводом scanf и выводом printf
# System V AMD64 ABI (Linux/macOS)

    .section .data
format_in:  .string "%hd %d %lld %f %lf"                                        # Формат ввода: short, int, long long, float, double
format_out: .string "i16: %hd, i32: %d, i64: %lld, f32: %.6f, f64: %.6lf\n"     # Формат вывода

    .section .text
    .global main
    .extern scanf
    .extern printf

main:
    # Пролог
    pushq   %rbp                	# Сохраняем базовый указатель
    movq    %rsp, %rbp          	# Устанавливаем новый базовый указатель

    # Резервируем место на стеке для локальных переменных
    subq    $32, %rsp           	# Резервируем 48 байт (2 + 4 + 8 + 4 + 8 = 26 байт)

    # Вызов scanf
    lea    -2(%rbp), %rsi           # 2-й: адрес i16
    lea    -6(%rbp), %rdx           # 3-й: адрес i32
    lea    -14(%rbp), %rcx          # 4-й: адрес i64
    lea    -18(%rbp), %r8           # 5-й: адрес f32
    lea    -26(%rbp), %r9           # 6-й: адрес f64
    
    #xorl    %eax, %eax             # Для variadic функций: 0 XMM-аргументов
    
    lea     format_in(%rip), %rdi   # 1-й аргумент: форматная строка
    call    scanf

    # Вызов printf
    movq    -2(%rbp), %rsi          # 2-й: i16 (знаковое расширение до 32 бит)
    movq    -6(%rbp), %rdx          # 3-й: i32
    movq    -14(%rbp), %rcx         # 4-й: i64
    movsd   -18(%rbp), %xmm0        # 5-й: f32 (загружаем как float)
    cvtss2sd %xmm0, %xmm0           # Конвертируем float в double для printf
    movsd   -26(%rbp), %xmm1        # 6-й: f64
    
    movl    $2, %eax               	# Указываем количество XMM-аргументов (2)
    
    lea     format_out(%rip), %rdi # 1-й аргумент: форматная строка
    call    printf

    # Эпилог
    movq    %rbp, %rsp              # Восстанавливаем указатель стека
    popq    %rbp
    
    #xorl    %eax, %eax          	# Возвращаем 0
    movl    $0, %eax 	       # Возвращаем 0
	
    ret
    