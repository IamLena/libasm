global ft_strlen

section .code

ft_strlen:
		cmp  rdi, 0				; check if str == NULL
		jz   .cycle_quit		; if str == NULL jump to quit
		xor  rax, rax			; rax = 0

.cycle:							; loop while str[i] != '\0', rdi - pointer to str, rax - i
		cmp  byte [rdi+rax], 0	; check if byte == 0
		jz   .cycle_quit		; if byte == 0 jump to quit
		inc  rax				; increment index
		jmp .cycle				; jump to cycle - loop

.cycle_quit:
		ret						; return from function
