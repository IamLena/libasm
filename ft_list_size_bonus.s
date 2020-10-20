global ft_list_size

section .code

ft_list_size:
	xor  rax, rax			;index and return value = 0
.loop:
	cmp  rdi, 0				;if list pointer == NULL => return
	jz   .quit
	inc  rax				;index++
	mov  rdi, [rdi+8]		;move to the next, the next pointer is after 8byte of void* pointer
	jmp  .loop

.quit:
	ret
