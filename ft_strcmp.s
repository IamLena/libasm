global ft_strcmp

section .code

ft_strcmp:
		cmp  rdi, 0				; check if str1 pointer == NULL
		jz   .cycle_quit
		cmp  rsi, 0				; check if str2 pointer == NULL
		jz   .cycle_quit
		cld						; clear direction flag for cmpsb

.cycle:							; loop while *str1 != '\0'
		cmp  byte [rdi], 0		; check if str1 ended
		jz   .cycle_quit		; if *str1 == '\0' jump to quit
		cmpsb					; cmp [rdi] and [rsi], inc rdi, inc rsi, set flags
		jnz  .false				; if [rsi] and [rdi] not equal jump false
		jmp  .cycle

.cycle_quit:
		cmp  byte [rsi], 0		; check if str2 ended
		jz   .true				; *str1 == '\0' => str1 and str2 equal, jump to true
		xor  rax, rax 			; set rax to 0
		sub  rax, [rsi]			; put difference *str1 (which is zero) - *str2 to rax for return
		jmp  .quit

.false:
		dec	 rdi				; decrement rdi, rsi, because cmpsb incremented it
		dec  rsi
		mov rax, [rdi]			; mov last str1 symbol to rax
		sub rax, [rsi]			; return *str1 - *str2
		jmp  .quit

.true:
		xor  rax, rax			; str1 and str2 is equal return 0;

.quit:
		ret
