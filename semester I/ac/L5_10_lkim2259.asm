;10. E(a,b,c,d) = max(min(a * 1.1, 1), 0) - b + sqrt(c / d)
%include 'io.inc'
%include 'mio.inc'
section .text
global main


main :
	xorps 		xmm0, xmm0
	xorps 		xmm1, xmm1
	xorps		xmm2, xmm2
	xorps 		xmm3, xmm3
	xorps 		xmm4, xmm4
	xorps 		xmm5, xmm5
	call 		ReadFloatsRegular
	call 		mio_writeln
	movss 		xmm1, xmm0
	xorps 		xmm0, xmm0
	call 		ReadFloatsExponential
	call		mio_writeln
	movss 		xmm2, xmm0
	xorps 		xmm0, xmm0
	call 		ReadFloatsRegular
	call 		mio_writeln
	movss 		xmm3, xmm0
	xorps 		xmm0, xmm0
	call 		ReadFloatsExponential
	call 		mio_writeln
	movss 		xmm4, xmm0
	xorps 		xmm0, xmm0
	
	movss 		xmm0, xmm1
	movss		xmm5, [onepointone]
	mulss 		xmm0, xmm5
	call 		mio_writeln
	call 		WriteFloatsRegular
	call 		mio_writeln
	call 		io_writeflt
	call 		mio_writeln
	xorps		xmm5, xmm5
	movss		xmm5, [one]
	minss 		xmm0, xmm5
	xorps		xmm5, xmm5
	movss 		xmm5, [null]
	maxss 		xmm0, xmm5
	subss 		xmm0, xmm2
	
	xorps 		xmm5, xmm5
	movss 		xmm5, xmm3
	divss 		xmm5, xmm4
	sqrtss 		xmm5, xmm5
	
	addss 		xmm0, xmm5
		
	call 		WriteFloatsRegular
	call 		mio_writeln
	call 		WriteFloatsExponential
    ret
	
ReadFloatsRegular:
	movd 		eax, xmm1
	push eax
	movd 		ebx, xmm2
	push ebx
	movd 		ecx, xmm3
	push ecx
	movd 		edx, xmm4
	push edx
	push edi
	xorps 		xmm2, xmm2
	xorps 		xmm3, xmm3
	xorps 		xmm4, xmm4
	movss 		xmm3, [pointone]
	movss 		xmm4, [pointone]
	xor 		edx, edx
	xor 		ebx, ebx	
	mov 		ebx, 1
	mov 		ecx, 10
	movss 		xmm2, [ten]
	xorps 		xmm0, xmm0
	.integers:
	xor 		eax, eax
	call 		mio_readchar
	call 		mio_writechar
	cmp 		al, '-'
	jne 		.notMinus
	mov 		edx, 1
	jmp 		.integers
	.notMinus:
	cmp 		al, 13
	je .end

	cmp 		al, '.'
	je .fractions

	sub 		eax, '0'
	xorps 		xmm1, xmm1
	CVTSI2SS 	xmm1, eax
	MULSS 		xmm0, xmm2
	ADDSS 		xmm0, xmm1
	jmp .integers
	.fractions:
	xor 		eax, eax
	call 		mio_readchar
	cmp 		al, 13
	je .end
	call 		mio_writechar
	sub 		eax, '0'
	xorps 		xmm1, xmm1
	CVTSI2SS 	xmm1, eax
	mulss 		xmm1, xmm3
	mulss 		xmm3, xmm4
	addss 		xmm0, xmm1
	jmp .fractions
	.end:
	cmp 		edx, 1
	jne 			.minus
	movss 		xmm2, [minusone]
	mulss 		xmm0, xmm2
	.minus:
	pop 		edi
	pop 		edx
	movd 		xmm4, edx
	pop ecx
	movd 		xmm3, ecx
	pop ebx
	movd 		xmm2, ebx
	pop eax
	movd 		xmm1, eax
	ret

WriteFloatsRegular:
	movd 		eax, xmm1
	push eax
	movd 		ebx, xmm2
	push ebx
	movd 		ecx, xmm3
	push ecx
	movd 		edx, xmm4
	push edx
	push edi
	movss 		xmm4, xmm0
	xor			ecx, ecx
	xorps 		xmm2, xmm2
	CVTTSS2SI 	eax, xmm0
	cmp 		eax, 0
	jne 		.notM
	
	comiss 		xmm0, [null]
	ja			.nnotM
	push		eax
	mov 		eax, '-'
	call 		mio_writechar
	pop 		eax
	.notM:
	.nnotM:
	call 		WriteInt
	CVTSI2SS 	xmm2, eax
	subss 		xmm0, xmm2
	xor 		eax, eax
	mov 		eax, '.'
	call 		mio_writechar
	mov 		ecx, 4
	.fract:
	cmp 		ecx, 0
	je 			.end
	.frct:
	xorps 		xmm1, xmm1
	movss		xmm1, [ten]
	mulss 		xmm0, xmm1
	CVTTSS2SI 	eax, xmm0
	cmp 		eax, 0
	jge 		.negFract
	movss 		xmm3, [minusone]
	mulss 		xmm0, xmm3
	jmp 		.frct
	.negFract:
	
	
	call 		WriteInt
	xorps 		xmm2, xmm2
	CVTSI2SS 	xmm2, eax
	subss 		xmm0, xmm2

	dec 		ecx
	jmp 		.fract
	.end:
	movss 		xmm0, xmm4
	pop 		edi
	pop 		edx
	movd 		xmm4, edx
	pop ecx
	movd 		xmm3, ecx
	pop ebx
	movd 		xmm2, ebx
	pop eax
	movd 		xmm1, eax
	ret
	
ReadFloatsExponential:
	movd 		eax, xmm1
	push eax
	movd 		ebx, xmm2
	push ebx
	movd 		ecx, xmm3
	push ecx
	movd 		edx, xmm4
	push edx
	push edi
	xor 		edi, edi
	xorps 		xmm2, xmm2
	xorps 		xmm3, xmm3
	xorps 		xmm4, xmm4
	movss 		xmm3, [pointone]
	movss 		xmm4, [pointone]
	xor 		edx, edx
	xor 		ebx, ebx	
	mov 		ecx, 10
	movss 		xmm2, [ten]
	xorps 		xmm0, xmm0
	xor 		eax, eax
	.readInteger:
	call 		mio_readchar
	call 		mio_writechar
	cmp 		al, '-'
	jne 		.notMinus
	mov 		edi, 1
	jmp 		.readInteger	
	.notMinus:
	cmp 		al, 13
	je .end
	sub 		eax, '0'
	xorps 		xmm1, xmm1
	CVTSI2SS 	xmm1, eax
	ADDSS 		xmm0, xmm1
	call 		mio_readchar
	call 		mio_writechar
	.fractions:
	xor 		eax, eax
	call 		mio_readchar
	call 		mio_writechar

	cmp 		al, 'e'
	je 			.exponential_term
	cmp 		al, 13
	je .end
	sub 		eax, '0'
	xorps 		xmm1, xmm1
	CVTSI2SS 	xmm1, eax
	mulss 		xmm1, xmm3
	mulss 		xmm3, xmm4
	addss 		xmm0, xmm1
	jmp .fractions
	
	.exponential_term:
	xor 		edx, edx
	.loopit:
	xor 		eax, eax
	call 		mio_readchar
	call 		mio_writechar
	cmp 		al, '-'
	jne 		.continue
	mov 		edx, 1
	jmp 		.loopit
	.continue:
	cmp 		al, 13
	je .multiply

	sub 		eax, '0'
	imul 		ebx, 10
	add 		ebx, eax
	jmp 		.loopit
	
	.multiply:
	cmp			edx, 1
	je 			.divide
	cmp 		ebx, 0
	je 			.end
	xorps 		xmm2, xmm2
	movss		xmm2, [ten]
	mulss 		xmm0, xmm2
	dec ebx
	jmp 		.multiply
	
	.divide:
	cmp 		ebx, 0
	je 			.end
	xorps 		xmm2, xmm2
	movss 		xmm2, [pointone]
	mulss		xmm0, xmm2
	dec ebx
	
	jmp .divide
	
	
	.end:
	cmp 		edi, 0
	je 			.notMin
	xorps 		xmm1, xmm1
	movss		xmm1, [minusone]
	mulss 		xmm0, xmm1
	.notMin:
	pop 		edi
	pop 		edx
	movd 		xmm4, edx
	pop ecx
	movd 		xmm3, ecx
	pop ebx
	movd 		xmm2, ebx
	pop eax
	movd 		xmm1, eax
	
ret

WriteFloatsExponential:
	movd 		eax, xmm1
	push eax
	movd 		ebx, xmm2
	push ebx
	movd 		ecx, xmm3
	push ecx
	movd 		edx, xmm4
	push edx
	push edi
	movss 		xmm4, xmm0
	xor 		edx, edx
	xor 		edi, edi
	xor			ecx, ecx
	
	CVTTSS2SI 	eax, xmm0
	cmp 		eax, 0
	jge			.greather
	movss		xmm2, [minusone]
	mulss 		xmm0, xmm2
	mov 		edx, 1
	.greather:
	
	xorps 		xmm2, xmm2
	CVTTSS2SI 	eax, xmm0
	cmp 		eax, 1
	jl 		.smallerthanten
	mov 		edi, 1
	cmp 		eax, 10
	jl 			.singledigit
	.notsingledigit:
	xorps 		xmm2, xmm2
	movss 		xmm2, [pointone]
	mulss 		xmm0, xmm2
	CVTTSS2SI 	eax, xmm0
	inc 		ecx
	cmp 		eax, 10
	jge 			.notsingledigit
	.singledigit:
	push 		eax
	CVTTSS2SI 	eax, xmm0

	xorps 		xmm2, xmm2
	CVTSI2SS 	xmm2, eax
	subss 		xmm0, xmm2
	
	
	cmp 		edx, 1
	jne 		.notNeg
	mov 		eax, '-'
	call 		mio_writechar
	.notNeg:
	pop 		eax
	call 		WriteInt
	mov 		eax, '.'
	call 		mio_writechar
	xor 		esi, esi
	mov 		esi, ecx
	mov 		ecx, 6
	.fractals:
	cmp 		ecx, 0
	je 			.fractals_end
	.frct1:
	xorps 		xmm1, xmm1
	movss		xmm1, [ten]
	mulss 		xmm0, xmm1
	CVTTSS2SI 	eax, xmm0
		cmp 		eax, 0
	jge 		.negFract1
	movss 		xmm3, [minusone]
	mulss 		xmm0, xmm3
	jmp 		.frct1
	.negFract1:
	call 		WriteInt
	xorps 		xmm2, xmm2
	CVTSI2SS 	xmm2, eax
	subss 		xmm0, xmm2
	dec 		ecx
	
	jmp 		.fractals
	.fractals_end:
	mov 		eax, 'e'
	call 		mio_writechar
	mov 		eax, esi
	call 		WriteInt
	jmp 		.end
	.smallerthanten:
	
	mov 		edi, 1
	xor 		ecx, ecx
	
	.notSnglDigit:
	xorps 		xmm1, xmm1
	movss 		xmm1, [ten]
	mulss 		xmm0, xmm1
	CVTTSS2SI 	eax, xmm0
	inc 		ecx
	cmp 		eax, 0
	je			.notSnglDigit
	
	push eax
	CVTTSS2SI 	eax, xmm0

	xorps 		xmm2, xmm2
	CVTSI2SS 	xmm2, eax
	subss 		xmm0, xmm2
	
	cmp 		edx, 1
	jne 		.notNegative
	mov 		eax, '-'
	call 		mio_writechar
	.notNegative:
	pop 		eax
	call 		WriteInt
	mov 		eax, '.'
	call 		mio_writechar
	xor 		esi, esi
	mov 		esi, ecx
	mov 		ecx, 6
	.fract:
	cmp 		ecx, 0
	je 			.fract_end
	.frct2:
	xorps 		xmm1, xmm1
	movss		xmm1, [ten]
	mulss 		xmm0, xmm1
	CVTTSS2SI 	eax, xmm0
	
	cmp 		eax, 0
	jge 		.negFract2
	movss 		xmm3, [minusone]
	mulss 		xmm0, xmm3
	jmp 		.frct2
	.negFract2:
	
	call 		WriteInt
	xorps 		xmm2, xmm2
	CVTSI2SS 	xmm2, eax
	subss 		xmm0, xmm2
	dec 		ecx
	
	jmp 		.fract
	.fract_end:
	mov 		eax, 'e'
	call 		mio_writechar
	mov 		eax, '-'
	call 		mio_writechar
	mov 		eax, esi
	call 		WriteInt
	.end:
	movss 		xmm0, xmm4
	pop 		edi
	pop 		edx
	movd 		xmm4, edx
	pop ecx
	movd 		xmm3, ecx
	pop ebx
	movd 		xmm2, ebx
	pop eax
	movd 		xmm1, eax
ret

WriteInt:				;(EAX):()– 32 bites előjeles egész kiírása
	
	
	push eax
	push ecx
	push edx
	
	push dword '£'
	
	cmp eax,0
	jl .negativ
	
	.tovabb:	
	mov ecx,10
	
	.ciklus1:
		xor edx,edx
		div ecx
		push edx
		cmp eax,0
		jne .ciklus1
	
	.ciklus2:
		pop eax
		cmp eax,'£'
		je .vege
		add eax,'0'
		call mio_writechar
		jmp .ciklus2
	
	.vege:
	pop edx
	pop ecx
	pop eax
ret

.negativ:
	push eax
	mov eax,'-'
	call mio_writechar
	pop eax
	neg eax
	jmp .tovabb
section .bss
    A   resd    256
    B   resd    256
    C   resd    256
	D	resd 	256

section .data
	minusone dd -1.0
	ten 	dd 10.0
	pointone dd 0.1
	onepointone dd 1.1
	one 		dd 1.0
	null		dd 0.0