# lr4_4_short.asm
# Программа с пятью локальными переменными, вводом scanf и выводом printf
# System V AMD64 ABI (Linux/macOS), укороченный пролог (адресация от rsp)

    .section .data
format_in: 
	.string "%hd %d %lld %f %lf"                             # Формат ввода: short, int, long long, float, double
format_out: 
	.string "i16=%hd i32=%d i64=%lld f32=%f f64=%lf\n"      # Формат вывода

    .section .text
    .global main
    .extern scanf
    .extern printf

main:

    # Резервируем место на стеке для локальных переменных
    subq    $40, %rsp               # Резервируем 40 байт (2 + 4 + 8 + 4 + 8 = 26 байт и 14 выравнивание)

    # Адреса локальных переменных относительно rsp:
	# i16: 24(%rsp) (выравнивание 2)
	# i32: 20(%rsp) (выравнивание 4)
	# i64: 16(%rsp) (выравнивание 4)
	# f32: 8(%rsp) 	(выравнивание 8)
	# f64: 0(%rsp) 	(выравнивание 8)

    lea    format_in(%rip), %rdi    # 1-й аргумент: форматная строка
    lea    24(%rsp), %rsi           # 2-й: адрес i16
    lea    20(%rsp), %r8            # 5-й: адрес f32
    lea    16(%rsp), %rdx           # 3-й: адрес i32
    lea    8(%rsp), %r9             # 6-й: адрес f64
    lea    0(%rsp), %rcx            # 4-й: адрес i64

    call    scanf                   # Вызов scanf

    leaq    format_out(%rip), %rdi  # 1-й аргумент: форматная строка
    movswl  24(%rsp), %esi          # 2-й: i16 
    movss   20(%rsp), %xmm0         # 5-й: f32 (загружаем как float)
    movl    16(%rsp), %edx          # 3-й: i32
    movsd   8(%rsp), %xmm1          # 6-й: f64
    movq    0(%rsp), %rcx           # 4-й: i64
	
    movl    $2, %eax                # Указываем количество XMM-аргументов (2)
    cvtss2sd %xmm0, %xmm0           # Конвертируем float в double
	
    call    printf                  # Вызов printf

    addq    $40, %rsp
    movl    $0, %eax
    ret
