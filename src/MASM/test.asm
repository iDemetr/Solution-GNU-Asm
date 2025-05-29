; test.asm
extrn puts:proc

.data
msg db "Hello, world!", 0

.code
main proc
    sub rsp, 28h           ; выравнивание стека (обязательно!)
    lea rcx, msg           ; первый параметр - адрес строки в rcx
    call puts              ; вызов puts
    xor eax, eax           ; возврат 0
    add rsp, 28h
    ret
main endp
end
