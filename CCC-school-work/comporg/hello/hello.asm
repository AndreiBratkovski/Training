; hello world in 64-bit intel assembly
section .data ; declares data section
	message db "Hello, World!", 10

; program part - code
section .text
	global _start

_start:
	mov rax, 1 ; eax (32-bit), ax (lower 16-bits), al ( lower 8-bits)
	mov rdi, 1
	mov rsi, message
	mov rdx, 14
	syscall

	mov rax, 60
	mov rdi, 0
	syscall

