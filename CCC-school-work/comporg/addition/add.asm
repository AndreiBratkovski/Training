; sample program doing some adding
; hello world in 64-bit intel assembly

section .data ; declares data section

; program part - code
section .text
	global _start

_start:
	mov rax, 37 ; eax (32-bit), ax (lower 16-bits), al ( lower 8-bits)
	mov rbx, 26
	add rax, rbx
	mov rcx, rax
	add rbx, 12
	mov r12, 2047
	mov r13, 262143
	add r12, r13
	mov r11, 0
	mov rdx, 0
	add rdx, r11

; return 0
	mov rax, 60
	mov rdi, 0
	syscall

