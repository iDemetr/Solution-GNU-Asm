; lr4_4.asm
; Программа с пятью локальными переменными, вводом scanf и выводом printf
; Microsoft x64 calling convention (Windows), укороченный пролог (адресация от rsp)


	.data
format_in db "%hd %d %lld %f %lf", 0
format_out db "i16=%hd i32=%d i64=%lld f32=%f f64=%lf", 10, 0

    	.code
    	extern scanf: proc
    	extern printf: proc
    	public main
    
main PROC
    sub rsp, 40           ; Выделяем теневое пространство (32 байта) + 8 байт для выравнивания
	
    ; Адреса локальных переменных относительно rsp:
    ; i16:  rsp+0
    ; i32:  rsp+2
    ; i64:  rsp+8
    ; f32:  rsp+16
    ; f64:  rsp+24

    ; Адреса локальных переменных
    lea rcx, format_in    			; форматная строка - 1-й параметр в rcx
    lea rdx, [rsp]     			; &i16 - 2-й параметр в rdx
    lea r8,  [rsp+2]     			; &i32 - 3-й параметр в r8
    lea r9,  [rsp+8]     			; &i64 - 4-й параметр в r9

    ; Параметры, которые не помещаются в регистры, кладём в стек
    ;lea rax, [rsp+16]     			; адрес f32
    ;mov qword ptr [24p], rax
    ;lea rax, [rsp+48]     			; адрес f64
    ;mov qword ptr [rsp+8], rax

    call scanf

    ; Загружаем значения переменных для printf    
    lea rcx, format_out    		; форматная строка printf в rcx
    movsx rdx, word ptr [rsp+24]     	; i16 -> rdx
    movsx r8, dword ptr [rsp+28]      ; i32 -> r8
    mov r9, qword ptr [rsp+32]      	; i64 -> r9
    movss xmm0, dword ptr [rsp+40]   	; f32 -> xmm0
    movsd xmm1, qword ptr [rsp+48]   	; f64 -> xmm1

    call printf

    	add rsp, 40		; Восстанавливаем указатель стека
	mov eax, 0 		; Возвращаем 0
    	ret
    
main ENDP
end
