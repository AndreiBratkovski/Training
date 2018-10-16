	.file	"primeregbs.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"%d"
	.align 8
.LC1:
	.string	"Bad Argument- must be greater than 0\n"
.LC2:
	.string	"No Upper Bound\n"
.LC3:
	.string	"2 3 "
.LC4:
	.string	"%d "
.LC6:
	.string	"%8.4lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 96
	mov	DWORD PTR -84[rbp], edi
	mov	QWORD PTR -96[rbp], rsi
	mov	DWORD PTR -4[rbp], 2
	mov	DWORD PTR -8[rbp], 3
	mov	DWORD PTR -12[rbp], 2
	cmp	DWORD PTR -84[rbp], 1
	jle	.L2
	mov	rax, QWORD PTR -96[rbp]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	lea	rdx, -68[rbp]
	lea	rsi, .LC0[rip]
	mov	rdi, rax
	mov	eax, 0
	call	__isoc99_sscanf@PLT
	mov	eax, DWORD PTR -68[rbp]
	test	eax, eax
	jg	.L3
	mov	rax, QWORD PTR stderr[rip]
	mov	rcx, rax
	mov	edx, 37
	mov	esi, 1
	lea	rdi, .LC1[rip]
	call	fwrite@PLT
	mov	edi, 0
	call	exit@PLT
.L2:
	mov	rax, QWORD PTR stderr[rip]
	mov	rcx, rax
	mov	edx, 15
	mov	esi, 1
	lea	rdi, .LC2[rip]
	call	fwrite@PLT
	mov	edi, 0
	call	exit@PLT
.L3:
	lea	rax, -48[rbp]
	mov	esi, 0
	mov	rdi, rax
	call	gettimeofday@PLT
	mov	rax, QWORD PTR stderr[rip]
	mov	rcx, rax
	mov	edx, 4
	mov	esi, 1
	lea	rdi, .LC3[rip]
	call	fwrite@PLT
	jmp	.L4
.L9:
	cvtsi2sd	xmm0, DWORD PTR -8[rbp]
	call	sqrt@PLT
	cvttsd2si	eax, xmm0
	mov	DWORD PTR -16[rbp], eax
	mov	eax, DWORD PTR -8[rbp]
	cdq
	idiv	DWORD PTR -4[rbp]
	mov	DWORD PTR -20[rbp], edx
	cmp	DWORD PTR -20[rbp], 0
	je	.L5
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, DWORD PTR -16[rbp]
	je	.L6
	add	DWORD PTR -4[rbp], 1
	jmp	.L4
.L6:
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, DWORD PTR -16[rbp]
	jne	.L8
	mov	rax, QWORD PTR stderr[rip]
	mov	edx, DWORD PTR -8[rbp]
	lea	rsi, .LC4[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	add	DWORD PTR -8[rbp], 1
	add	DWORD PTR -12[rbp], 1
	mov	DWORD PTR -4[rbp], 2
	jmp	.L4
.L8:
	mov	rax, QWORD PTR stderr[rip]
	mov	edx, DWORD PTR -8[rbp]
	lea	rsi, .LC4[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	add	DWORD PTR -8[rbp], 1
	add	DWORD PTR -12[rbp], 1
	mov	DWORD PTR -4[rbp], 2
	jmp	.L4
.L5:
	add	DWORD PTR -8[rbp], 1
	mov	DWORD PTR -4[rbp], 2
.L4:
	mov	eax, DWORD PTR -68[rbp]
	cmp	DWORD PTR -12[rbp], eax
	jne	.L9
	lea	rax, -64[rbp]
	mov	esi, 0
	mov	rdi, rax
	call	gettimeofday@PLT
	mov	rdx, QWORD PTR -64[rbp]
	mov	rax, QWORD PTR -48[rbp]
	sub	rdx, rax
	mov	rax, rdx
	cvtsi2sd	xmm1, rax
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -40[rbp]
	sub	rdx, rax
	mov	rax, rdx
	cvtsi2sd	xmm0, rax
	movsd	xmm2, QWORD PTR .LC5[rip]
	divsd	xmm0, xmm2
	addsd	xmm0, xmm1
	mov	rax, QWORD PTR stdout[rip]
	lea	rsi, .LC6[rip]
	mov	rdi, rax
	mov	eax, 1
	call	fprintf@PLT
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC5:
	.long	0
	.long	1093567616
	.ident	"GCC: (Debian 7.2.0-19) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
