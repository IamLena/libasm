global ft_strdup

extern ft_strcpy
extern ft_strlen
extern malloc

section .code

ft_strdup:
	push rdi			; save str pointer so ft_strlen wont break it

.ft_strlen:					;not calling ft_strlen function, so it will segfault
	xor  rax, rax			; rax = 0

.cycle:						; loop while str[i] != '\0', rdi - pointer to str, rax - i
	cmp  byte [rdi+rax], 0	; check if byte == 0
	jz   .cycle_quit		; if byte == 0 jump to quit
	inc  rax				; increment index
	jmp .cycle				; jump to cycle - loop

.cycle_quit:
	inc  rax			; for '\0'
	mov  rdi, rax		; pass rax to rdi to call malloc with rdi as argument
	call malloc			;returns mem adress to rax

	pop  rsi			; pop str pointer to rsi, doing before return to reset stack
	cmp  rax, 0			; if malloc returned 0 => return
	jz   .return

	mov  rdi, rax		; move allocated buf (rax) to rdi, for ft_strcpy call
	call ft_strcpy		; ft_strcpy(rdi, rsi)

.return:
	ret
