global ft_write

extern __errno_location

section .code

ft_write:
	call __errno_location		; return errno addres to rax
	mov rbx, 0					; set errno to zero
	mov [rax], rbx
	mov  rax, 1					; sys call number for write is 1
	syscall						; rdi = fd, rsi = msg, rdx = length

	cmp rax, 0					; if write result (rax) is positive or zero => return
	jl .error
	ret

.error:
	; error occured rax = -error
	neg rax						; take abs
	push rax					; save the error code
	call __errno_location		; return errno addres to rax
	pop	rdx						; get the error value to rdx
	mov [rax], rdx				; move error to error adress
	mov rax, -1					; return -1 from fuction
	ret
