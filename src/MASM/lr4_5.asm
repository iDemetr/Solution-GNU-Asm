; lr4_5.asm
; Программа с пятью локальными переменными, вводом scanf и выводом printf
; Microsoft x64 calling convention (Windows) , классический пролог (rbp фиксирован)
  
 	.data
 format_in db "%hd %d %lld %f %lf", 0
 format_out db "i16=%hd i32=%d i64=%lld f32=%f f64=%lf", 10, 0
  
    .code
    extern scanf: proc
    extern printf: proc
    public main
     
 main PROC
     push rbp               			; Сохраняем базовый указатель
     mov rbp, rsp           			; Устанавливаем новый базовый указатель
     sub rsp, 48            			; Выделяем 32 байт на стеке
  
     ; Передача параметров в scanf
     lea rcx, format_in     			; форматная строка - 1-й параметр в rcx
     lea rdx, [rbp - 2]     			; адрес &i16 - 2-й параметр в rdx
     lea r8,  [rbp - 6]     			; адрес &i32 - 3-й параметр в r8
     lea r9,  [rbp - 14]    			; адрес &i64 - 4-й параметр в r9
     
     ; Параметры не помещаются в регистры, кладём в стек
     ;lea rax, [rbp - 18]
	;mov qword ptr [rsp], rax			; адрес &f32 в стек
	;lea rax, [rbp - 26]
     ;mov qword ptr [rsp + 8], rax 		; адрес &f64 в стек
  
     call scanf
  
     ; Передача параметров в printf
     lea rcx, format_out     			; форматная строка - 1-й параметр в rcx
     movsx rdx, word ptr [rbp - 2]   		; i16 -> rdx
     movzx r8, word ptr [rbp - 6]     	; i32 -> r8
     mov r9, qword ptr [rbp - 14]     	; i64 -> r9
     movss xmm0, dword ptr [rbp - 18]   	; f32 -> xmm0
     movsd xmm1, qword ptr [rbp - 26]   	; f64 -> xmm1
  
     call printf
  
     mov rsp, rbp          ; Восстанавливаем указатель стека
     pop rbp               ; Восстанавливаем базовый указатель
     mov eax, 0            ; Возвращаем 0
     ret
     
 main ENDP
 end
