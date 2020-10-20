global ft_list_remove_if

extern free

section .code

ft_list_remove_if:				; rdi = list, rsi = data, rdx = func
	cmp  rdi, 0					; check if list != NULL
	jz   .quit
	mov  rbx, [rdi]				; rbx - cur element
	xor  rcx, rcx				; rcx - prev element

.loop:
	cmp  rbx, 0					; end of list
	jz   .quit

	push rdi					; save pointer to list head
	push rsi
	mov rdi, [rbx]				; mov elem's content to rdi for func call; rsi = rsi data
	call rdx					; func(elem data, passed data)
	pop rsi
	pop  rdi					; pop pointer to list head
	cmp  rax, 0					; if elems are equal
	jz   .delete

	mov rcx, rbx
	mov rbx, [rbx + 8]			; move to the next element
	jmp  .loop

.delete:						; delete rbx elem
	; if prev == NUll; [rdi] = [rbx + 8] change head
	cmp rcx, 0
	jz .update_head
	mov rax, [rbx + 8]			; prev->next = cur->next
	mov [rcx + 8], rax
	; push rdi
	; mov rdi, rbx
	mov rbx, rax					; move to the next element
	; call free
	; pop rdi
	jmp .loop

.update_head:
	mov rax, [rbx + 8]			; prev->next = cur->next
	mov [rdi], rax
	; push rdi
	; mov rdi, rbx
	; call free
	; pop rdi
	xor rcx, rcx
	mov rbx, [rdi]
	jmp .loop

.quit:
	ret
