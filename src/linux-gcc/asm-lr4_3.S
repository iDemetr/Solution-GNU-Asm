.section .data
msg:
    .asciz "Группа: ПИН-31Д\nНомер: 17\nВыполнил: Понкращенков Д.Б.\n"

.section .text
.global main
.extern puts

main:
    # Параметры main отсутствуют
    # rsp выровнен по 16 байтам при входе в main

    lea msg(%rip), %rdi    # адрес строки в RDI
    call puts              # вызов puts

    movl $0, %eax          # код возврата 0
    ret
