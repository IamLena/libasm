global ft_list_push_front

extern malloc

ft_list_push_front:
	cmp  rdi, 0			;if list NULL (which is list** type)
	jz   .quit
	push rdi			;save list head
	push rsi			;save content before calling malloc
	mov  rdi, 16		;malloc 8 byte => void * content, list * next
	call malloc
	pop rsi				;pop content
	pop rdi				;pop pointer to head
	cmp  rax, 0			;check for malloc error
	jz   .quit
	mov [rax], rsi		;set content
	mov rdx, [rdi]
	mov [rax+8], rdx	;set next elem to *list
	mov [rdi], rax		;return new head
.quit:
	ret
