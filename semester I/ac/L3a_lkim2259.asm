%include 'mio.inc'
global main

section .text

writeBin:
	push edx
	push ebx
    push eax
	mov edx, 4
	mov ebx, eax
	mov ecx, 32
	.kiirat:
	cmp edx, 0
	jg .space
	push eax
	mov eax, ' '
	call mio_writechar
	pop eax
	mov edx, 4
	.space:
	xor eax, eax
	shl ebx, 1
	adc eax, 48
	call mio_writechar
	dec edx
	loop .kiirat
    pop eax
	pop ebx
	pop edx
ret

	
readHex:
	push ebx
	mov ebx, 0
	.be:
	xor eax, eax
	call mio_readchar
	cmp al, 13
	je .vege
	
	cmp al, '0'
	jl .hiba
	cmp al, 'g'
	jg .hiba
	cmp al, '9'
	jg .elsoIntervallum
	.be_masodikba:
	cmp al, 'G'
	jg .masodikIntervallum
	.folytat:
	call mio_writechar
	imul ebx, 16
	
	cmp eax, 'a'
	je .A
	cmp eax, 'b'
	je .B
	cmp eax, 'c'
	je .C
	cmp eax, 'd'
	je .D
	cmp eax, 'e'
	je .E
	cmp eax, 'f'
	je .F
	sub eax, '0'
	jmp .hozzaad
	.A:
		mov eax, 10
		jmp .hozzaad
		
	.B:
		mov eax, 11
		jmp .hozzaad
		
	.C:
		mov eax, 12
		jmp .hozzaad
	
	.D:
		mov eax, 13
		jmp .hozzaad
	
	.E:
		mov eax, 14
		jmp .hozzaad
	
	.F:
		mov eax, 15
		jmp .hozzaad	
		
	.hozzaad:
	
	
	add ebx, eax
	jmp .be

	
.elsoIntervallum:
	cmp al, 'A'
	jl .hiba
	jge .be_masodikba
.masodikIntervallum:
	cmp al, 'a'
	jl .hiba
	jge .folytat
.hiba:
	mov eax, str_hiba
	call mio_writeln
	call mio_writestr
	.vege:
	mov eax, ebx
	pop ebx
	ret
	

main:
call readHex
call mio_writeln
push eax
call writeBin
call mio_writeln
call readHex
call mio_writeln
call writeBin
call mio_writeln
pop ebx
add eax, ebx
push eax
mov eax, str_eredmeny
call mio_writestr
call mio_writeln
pop eax
call writeBin
ret

section .text
	Hexa db "0x", 0
	str_hiba db "Hiba: Helytelen karaktert adtal meg!", 0
	str_eredmeny db "Eredmeny:" , 0