	.arch armv8-a
	.file	"decomment.c"
	.text
	.align	2
	.global	handleNotInCommentState
	.type	handleNotInCommentState, %function
handleNotInCommentState:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 47
	bne	.L2
	mov	w0, 1
	b	.L3
.L2:
	ldr	w0, [sp, 28]
	cmp	w0, 34
	bne	.L4
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 4
	b	.L3
.L4:
	ldr	w0, [sp, 28]
	cmp	w0, 39
	bne	.L5
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 7
	b	.L3
.L5:
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
.L3:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	handleNotInCommentState, .-handleNotInCommentState
	.align	2
	.global	handleSlashState
	.type	handleSlashState, %function
handleSlashState:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 42
	bne	.L7
	mov	w0, 32
	bl	putchar
	mov	w0, 2
	b	.L8
.L7:
	ldr	w0, [sp, 28]
	cmp	w0, 47
	bne	.L9
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 1
	b	.L8
.L9:
	ldr	w0, [sp, 28]
	cmp	w0, 34
	bne	.L10
	mov	w0, 47
	bl	putchar
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 4
	b	.L8
.L10:
	ldr	w0, [sp, 28]
	cmp	w0, 39
	bne	.L11
	mov	w0, 47
	bl	putchar
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 7
	b	.L8
.L11:
	mov	w0, 47
	bl	putchar
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
.L8:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	handleSlashState, .-handleSlashState
	.align	2
	.global	handleInCommentState
	.type	handleInCommentState, %function
handleInCommentState:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 42
	bne	.L13
	mov	w0, 3
	b	.L14
.L13:
	ldr	w0, [sp, 28]
	cmp	w0, 10
	bne	.L15
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 2
	b	.L14
.L15:
	mov	w0, 2
.L14:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	handleInCommentState, .-handleInCommentState
	.align	2
	.global	handleInCommentStarState
	.type	handleInCommentStarState, %function
handleInCommentStarState:
.LFB3:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 47
	bne	.L17
	mov	w0, 0
	b	.L18
.L17:
	ldr	w0, [sp, 28]
	cmp	w0, 42
	bne	.L19
	mov	w0, 3
	b	.L18
.L19:
	ldr	w0, [sp, 28]
	cmp	w0, 10
	bne	.L20
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 2
	b	.L18
.L20:
	mov	w0, 2
.L18:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	handleInCommentStarState, .-handleInCommentStarState
	.align	2
	.global	handleInStringState
	.type	handleInStringState, %function
handleInStringState:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 34
	bne	.L22
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
	b	.L23
.L22:
	ldr	w0, [sp, 28]
	cmp	w0, 92
	bne	.L24
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 5
	b	.L23
.L24:
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 4
.L23:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE4:
	.size	handleInStringState, .-handleInStringState
	.align	2
	.global	handleEscapeInStringState
	.type	handleEscapeInStringState, %function
handleEscapeInStringState:
.LFB5:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 4
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE5:
	.size	handleEscapeInStringState, .-handleEscapeInStringState
	.align	2
	.global	handleEscapeInCharState
	.type	handleEscapeInCharState, %function
handleEscapeInCharState:
.LFB6:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 7
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE6:
	.size	handleEscapeInCharState, .-handleEscapeInCharState
	.align	2
	.global	handleInCharState
	.type	handleInCharState, %function
handleInCharState:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 39
	bne	.L30
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
	b	.L31
.L30:
	ldr	w0, [sp, 28]
	cmp	w0, 92
	bne	.L32
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 6
	b	.L31
.L32:
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 7
.L31:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE7:
	.size	handleInCharState, .-handleInCharState
	.section	.rodata
	.align	3
.LC0:
	.string	"Error: line %d: unterminated comment\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB8:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	mov	w0, 1
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	str	w0, [sp, 44]
	ldr	w0, [sp, 28]
	str	w0, [sp, 40]
	str	wzr, [sp, 36]
	str	wzr, [sp, 32]
	b	.L34
.L44:
	ldr	w0, [sp, 32]
	cmp	w0, 7
	beq	.L35
	ldr	w0, [sp, 32]
	cmp	w0, 7
	bhi	.L36
	ldr	w0, [sp, 32]
	cmp	w0, 6
	beq	.L37
	ldr	w0, [sp, 32]
	cmp	w0, 6
	bhi	.L36
	ldr	w0, [sp, 32]
	cmp	w0, 5
	beq	.L38
	ldr	w0, [sp, 32]
	cmp	w0, 5
	bhi	.L36
	ldr	w0, [sp, 32]
	cmp	w0, 4
	beq	.L39
	ldr	w0, [sp, 32]
	cmp	w0, 4
	bhi	.L36
	ldr	w0, [sp, 32]
	cmp	w0, 3
	beq	.L40
	ldr	w0, [sp, 32]
	cmp	w0, 3
	bhi	.L36
	ldr	w0, [sp, 32]
	cmp	w0, 2
	beq	.L41
	ldr	w0, [sp, 32]
	cmp	w0, 2
	bhi	.L36
	ldr	w0, [sp, 32]
	cmp	w0, 0
	beq	.L42
	ldr	w0, [sp, 32]
	cmp	w0, 1
	beq	.L43
	b	.L36
.L42:
	ldr	w0, [sp, 24]
	bl	handleNotInCommentState
	str	w0, [sp, 32]
	str	wzr, [sp, 36]
	b	.L36
.L43:
	ldr	w0, [sp, 24]
	bl	handleSlashState
	str	w0, [sp, 32]
	str	wzr, [sp, 36]
	b	.L36
.L41:
	ldr	w0, [sp, 24]
	bl	handleInCommentState
	str	w0, [sp, 32]
	mov	w0, 1
	str	w0, [sp, 36]
	b	.L36
.L40:
	ldr	w0, [sp, 24]
	bl	handleInCommentStarState
	str	w0, [sp, 32]
	mov	w0, 1
	str	w0, [sp, 36]
	b	.L36
.L39:
	ldr	w0, [sp, 24]
	bl	handleInStringState
	str	w0, [sp, 32]
	str	wzr, [sp, 36]
	b	.L36
.L38:
	ldr	w0, [sp, 24]
	bl	handleEscapeInStringState
	str	w0, [sp, 32]
	str	wzr, [sp, 36]
	b	.L36
.L37:
	ldr	w0, [sp, 24]
	bl	handleEscapeInCharState
	str	w0, [sp, 32]
	str	wzr, [sp, 36]
	b	.L36
.L35:
	ldr	w0, [sp, 24]
	bl	handleInCharState
	str	w0, [sp, 32]
	str	wzr, [sp, 36]
	nop
.L36:
	ldr	w0, [sp, 24]
	cmp	w0, 10
	bne	.L34
	ldr	w0, [sp, 44]
	add	w0, w0, 1
	str	w0, [sp, 44]
	ldr	w0, [sp, 36]
	cmp	w0, 0
	bne	.L34
	ldr	w0, [sp, 44]
	str	w0, [sp, 40]
.L34:
	bl	getchar
	str	w0, [sp, 24]
	ldr	w0, [sp, 24]
	cmn	w0, #1
	bne	.L44
	ldr	w0, [sp, 32]
	cmp	w0, 1
	bne	.L45
	mov	w0, 47
	bl	putchar
.L45:
	ldr	w0, [sp, 36]
	cmp	w0, 1
	bne	.L46
	adrp	x0, stderr
	add	x0, x0, :lo12:stderr
	ldr	x3, [x0]
	ldr	w2, [sp, 40]
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	mov	x0, x3
	bl	fprintf
.L46:
	ldr	w0, [sp, 36]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.5.0 20240719 (Red Hat 11.5.0-14)"
	.section	.note.GNU-stack,"",@progbits
