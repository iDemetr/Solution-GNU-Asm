; team_win.asm
; Ассемблерная программа, вызывающая puts() для вывода строки
; Microsoft x64 calling convention (Windows)

.data
msg db "Группа: ПИН-31Д", 10, "Номер: 17", 10, "Выполнил: Понкращенков Д.Б.", 0

.code
public main
extern puts: proc

main PROC
    sub rsp, 32           ; Выделяем shadow space и выравниваем стек

    lea rcx, msg          ; Первый параметр - адрес строки
    call puts             ; Вызов puts

    add rsp, 32           ; Восстанавливаем rsp

    mov eax, 0            ; Возвращаем 0
    ret
main ENDP
end
