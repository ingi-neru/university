;10. E(a,b) = sqrt(max(a + b / 2, 4)) + a^2 - b^3
%include 'io.inc'
section .text
global main


main :
	
	.readInt:
	xor 	eax, eax
	call io_readint
	mov 	[N], eax
	xor 	ebx, ebx
	mov 	ebx, 4
	cdq
	idiv 	ebx
	cmp 	edx, 0
	jne 	.readInt
	
    mov       ebx, A
    call      ReadFloats
    call      io_writeln
	
	mov 	  eax, str_A
	call      io_writestr
	call  	  io_writeln
	
    mov       ebx, A
    call      WriteFloats
    call      io_writeln


    mov       ebx, B
    call      ReadFloats
    call      io_writeln
	
	mov       eax, str_B
	call      io_writestr
	call 	  io_writeln
	
	
    mov       ebx, B
    call      WriteFloats
    call      io_writeln
	
	xor    	  eax, eax
	xor 	  ebx, ebx
    mov       eax, A
    mov       ebx, B
    mov       edx, C
    call      CalcFloats
	
	mov  	  eax, str_eredmeny
	call 	  io_writestr
	call 	  io_writeln

    mov       ebx, C
    call      WriteFloats
    call      io_writeln

    ret

ReadFloats :  ; EBX - memory address
    push      ecx
	push      eax
	xor 	  eax, eax
  .read :
	xorps 	  xmm0, xmm0
    call      io_readflt
    movss     [ebx], xmm0
    inc		  eax
	add 	  ebx, 4
	cmp 	  eax, [N]
	jl   	  .read
	pop       eax
    pop       ecx
    ret

WriteFloats :  ; EBX - memory address	
	push 	  eax
    push      ecx
	xor 	  eax, eax
  .write :
    movss     xmm0, [ebx]
    call      io_writeflt
	call 	  io_writeln
	inc 	  eax
	add 	  ebx, 4
	cmp 	  eax, [N]
	jl 	  .write  
    pop       ecx
	pop 	  eax
    ret

CalcFloats :  ; EAX - array A, EBX - array B, EDX - C array
    push      ecx
	xor 	  ecx, ecx
	mov 	  ecx, [N]
  .calc :
    movups    xmm0, [eax]
    movups    xmm1, [ebx]
	movups 	  xmm3, xmm0
	movups 	  xmm4, xmm1
	movups    xmm5, xmm1
	movups 	  xmm2, [two]
	movups    xmm6, [four]
	
	divps 	  xmm1, xmm2
	addps 	  xmm0, xmm1
	maxps     xmm0, xmm6
	sqrtps 	  xmm0, xmm0
	
	
	mulps 	  xmm3, xmm3

    mulps 	  xmm4, xmm4
	mulps     xmm4, xmm5
	
	addps     xmm0, xmm3
	subps     xmm0, xmm4
	
    movups     [edx], xmm0
	add 	  eax, 16
	add 	  ebx, 16
	add 	  edx, 16
	loop .calc
	jl 		  .calc
    pop       ecx
    ret

section .bss
    A   resd    400
    B   resd    400
    C   resd    400

section .data
    two   dd  2.0, 2.0, 2.0, 2.0
	four  dd  4.0, 4.0, 4.0, 4.0
	N 		dd 	4
	str_A   dd "Az A tomb tartalma:", 0
	str_B   dd "A B tomb tartalma:", 0
	str_eredmeny dd "A paronkenti eredemnyek tombje:", 0