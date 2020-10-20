global ft_strcpy

section .code

ft_strcpy:
		push rdi				; save buf pointer

		cmp  rdi, 0				; check if buf pointer == NULL
		jz   .quit				; if buf == NULL jump to quit
		cmp  rsi, 0				; check if str pointer == NULL
		jz   .quit				; if str == NULL jump to quit
		cld						; clear direction flag for movsb

.cycle:							; loop till end of str
		cmp  byte [rsi], 0		; check if *str == '\0'
		jz   .quit				; if *str == '\0' jump to quit
		movsb					; copy byte from [rsi] to [rdi] and increment rsi, rdi
		jmp  .cycle				; jump to cycle for loop

.quit:
		mov rax, 0				; move 0 to rax
		mov [rdi], rax			; set [rdi] to 0, end of str
		pop rax					; pop saved buf pointer to rax, so it will be returned from function
		ret
