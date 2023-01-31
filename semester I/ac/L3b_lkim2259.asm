;10. 11, A[12:12] OR C[26:26], A[31:25] XOR B[24:18], C[7:7], B[31:30] AND 11, A[24:6]
%include 'mio.inc'
global main

section .text

writeInt:
	mov esi, 10
	push eax
	push ebx
	push edi
	mov edi, 0
	cmp eax, 0
	jge .pozitiv
	neg eax
	mov ebx, eax
	mov eax, '-'
	call mio_writechar
	mov eax, ebx
	
	.pozitiv:
	mov ebx, 10
	xor ecx, ecx
	.feldolgozSzam:
	cmp eax, 0
	je .vege
	cmp eax, 10
	jge .nemTulcs	
	mov esi, eax
	jmp .vege
	.nemTulcs:
	cdq
	div ebx
	imul ecx, 10
	add ecx, edx
	inc edi
	jmp .feldolgozSzam
	


.vege:
	cmp esi, 10
	je .overflow
	mov eax, esi
	add eax, '0'
	call mio_writechar
	.overflow:
	mov eax, ecx
	.label:
	cmp eax, 0
	je .kilep
	
	xor edx, edx
	div ebx
	push eax
	mov eax, edx
	add eax, '0'
	call mio_writechar
	dec edi
	pop eax
	jmp .label
	
	.kilep:
	cmp edi, 0
	je .v
	mov al, '0'
	call mio_writechar
	dec edi
	jmp .kilep
	.v:
	pop edi
	pop ebx
	pop eax
	cmp esi, 10
	ret



readHex:
	push ebx
	mov ebx, 0
	.be:
	xor eax, eax
	call mio_readchar
	cmp al, 13
	je .vege
	
	cmp al, '0';hibakereses
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
	cmp eax, 'A'
	je .A
	cmp eax, 'B'
	je .B
	cmp eax, 'C'
	je .C
	cmp eax, 'D'
	je .D
	cmp eax, 'E'
	je .E
	cmp eax, 'F'
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

	writeBin:
	push edx
	push ebx
    push eax
	mov edx, 4
	mov ebx, eax
	mov ecx, 32
	.kiirat:
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


main:
call readHex
call mio_writeln
mov [A], eax
call readHex
call mio_writeln
mov [B], eax
call readHex
call mio_writeln
mov [C], eax
mov eax, 0xC0000000;betesszuk az elso ket bitet az eax-ba

mov [D], eax
mov ebx, [A]
mov edx, [C]
shr ebx, 12
shr edx, 26
xor ecx, ecx
or ebx, edx
shr ebx, 1
adc ecx, 0
shl ecx, 29
add eax, ecx;a kapott bitet hozzaadjuk az eaxhez
mov ebx, [A]
mov edx, [B]
shl edx, 7
xor ebx, edx
xor edx, edx
mov ecx, 7
.bitshift:

shl ebx, 1
adc edx, 0
shl edx, 1
sub ecx, 1
cmp ecx, 1
jge .bitshift
shl edx, 21
add eax, edx

mov edx, [C]
xor ebx, ebx
shr edx, 8
adc ebx, 0
shl ebx, 21
add eax, ebx

mov edx, [B]
mov ebx, 0xC0000000
and edx, ebx
xor ecx, ecx
shl edx, 1
adc ecx, 0
shl ecx, 1
shl edx, 1
adc ecx, 0
shl ecx, 19
add eax, ecx

mov edx, [A]
shl edx, 7
shr edx, 13
add eax, edx
call writeBin
ret

section .data

A dd 0
B dd 0
C dd 0
D dd 0
	Hexa db "0x", 0
	str_hiba db "Hiba: Helytelen karaktert adtal meg! ", 0
shiftel dd 0
	;10. 11, A[12:12] OR C[26:26], A[31:25] XOR B[24:18], C[7:7], B[31:30] AND 11, A[24:6]