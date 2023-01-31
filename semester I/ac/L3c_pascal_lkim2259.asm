%include 'mio.inc'
global main

section .text

read_str_pascal:  ;reads a string to the memory tag stored in edi
	pusha
	
	xor 	eax, eax
	mov 	ecx, 0
	
  .readchar:
	
	call 	mio_readchar
	
	; stop condition (Enter pressed)
	cmp 	al, 13
	je 		.end
	
	call 	mio_writechar
	
	; write character into memory
	inc 	ecx
	mov 	[edi + ecx], al
	
	jmp 	.readchar

  .end:
	mov 	[edi], cl
	
	popa
	ret 
	
write_str_pascal: ;writes a string starting from the memory tag stored in edi
	pusha
	
	xor 	cl, cl
	mov 	cl, [edi]
	
	cmp 	cl, 0
	je		.end
	
  .writechar:
	
	inc 	edi
	dec 	cl
	mov 	al, [edi]
	
	call 	mio_writechar
	
	; stop condition 
	cmp 	cl, 0
	jg		.writechar

  .end:

	popa
	ret

main:
call read_str_pascal
call write_str_pascal
ret

section .bss
str_a resb 256
str_b resb 256
str_c resb 512
