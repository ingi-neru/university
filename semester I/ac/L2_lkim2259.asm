;Laszlo Kazmer
;2259 - bejelentkezesi azonosito
;512es csoport
;beolvas egy számot decimális egészként,
;kiíratja decimális (előjeles egész) alakban,
;kiíratja hexadecimális (a szám komplementerkódbeli ábrázolása) alakban,
;beolvas egy másik számot hexadecimális egészként (ezt egy egész komplementerkódbeli ábrázolásának tekintjük),
;kiíratja decimális (előjeles egész) alakban,
;kiíratja hexadecimális alakban,
;a két számot összeadja,
;az eredményt kiíratja decimális (előjeles egész) alakban,
;az eredményt kiíratja hexadecimális alakban.

%include 'mio.inc'
%include 'io.inc'
global main

section .text

readInt:
	push ebx
	push ecx
	mov ebx, 0
	mov ecx, 0;az ebx-be felepitjuk a szamot, az ecx-et az elojel vizsgalatara hasznaljuk
	.be:
	xor eax, eax
	call mio_readchar
	cmp al, '-'
	jne .nemMinusz
	mov ecx, 1
	call mio_writechar
	jmp .be
	.nemMinusz:
	
	cmp al, 13
	je .vege
	cmp al, '0';hibakereses
	jl .hiba
	cmp al, '9'
	jg .hiba
	call mio_writechar
	imul ebx, 10
	sub al,'0'
	add ebx, eax
	jmp .be

.hiba:
	mov eax, str_hiba
	call mio_writeln
	call mio_writestr
.vege:
	cmp ecx, 1
	jne .nemNegativ
	neg ebx
	.nemNegativ:
	mov eax, ebx
	pop ecx
	pop ebx
	ret
	
writeInt:
	mov esi, 10;tulcsordulas ellenorzesehez szukseges regiszter
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
	jge .nemTulcs;mivel a szam megforditva lesz eltarolva, ezert mindig a 10. szamjegyet(ha van) kulon elmenti hogy ne legyen tulcsordulas
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

	
	
writeHex:
push edi
push esi
push ecx
push eax	
xor edi, edi
mov ebx, 16
	xor ecx, ecx
	.lebont:
	cmp eax, 0
	je .vege
	xor edx, edx
	div ebx
	imul ecx, 16
	add ecx, edx
	inc edi
	jmp .lebont
	


.vege:
	mov esi, edi
	sub edi, 8
	cmp edi, 0
	mov eax, Hexa
	call mio_writestr
	.vge:
	cmp edi, 0
	je .tovabb
	mov eax, 0
	add eax, '0'
	call mio_writechar
	inc edi
	jmp .vge



	.tovabb:
	mov eax, ecx
	.folyt:
	cmp eax, 0
	je .kilep
	xor edx, edx
	div ebx
	push eax
	mov eax, edx
	
	cmp eax, 10;itt kezdodik az esetkezeles a karakterekre
	je .A
	cmp eax, 11
	je .B
	cmp eax, 12
	je .C
	cmp eax, 13
	je .D
	cmp eax, 14
	je .E
	cmp eax, 15
	je .F
	add eax, '0'
	jmp .le
	.A:
		mov eax, 'A'
		jmp .le
		
	.B:
		mov eax, 'B'
		jmp .le
		
	.C:
		mov eax, 'C'
		jmp .le
	
	.D:
		mov eax, 'D'
		jmp .le
	
	.E:
		mov eax, 'E'
		jmp .le
	
	.F:
		mov eax, 'F'
		jmp .le	
		
	.le:
	dec esi
	call mio_writechar
	pop eax
	jmp .folyt
	.kilep:
	cmp esi, 0
	je .v
	mov al, '0'
	call mio_writechar
	dec esi
	jmp .kilep
	.v:
	pop eax
	pop ecx
	pop esi
	pop edi
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
mov eax, str_elso
call mio_writestr

call readInt

call mio_writeln
push eax
mov eax, str_dec
call mio_writestr
pop eax

call writeInt

call mio_writeln
push eax
mov eax, str_hex
call mio_writestr
pop eax
call writeHex
push eax
call mio_writeln
call mio_writeln
push eax
mov eax, str_masodik
call mio_writestr
pop eax


call readHex

call mio_writeln
push eax
mov eax, str_dec
call mio_writestr
pop eax

call writeInt

call mio_writeln
push eax
mov eax, str_hex
call mio_writestr
pop eax

call writeHex
call mio_writeln
call mio_writeln
push eax
mov eax, str_osszegdec
call mio_writestr
pop eax
pop ebx

add eax, ebx

call writeInt

call mio_writeln
push eax
mov eax, str_osszeghex
call mio_writestr
pop eax

call writeHex



ret

section .text
	Hexa db "0x", 0
	str_hiba db "Hiba: Helytelen karaktert adtal meg! ", 0
	str_elso db "Add meg az elso szamot: ", 0
	str_masodik db "Add meg a masodik szamot: ", 0
	str_dec db "A szam decimalis formaja: ", 0
	str_hex db "A szam hexadecimalis formaja: ", 0
	str_osszegdec db "Az eredmeny decimalis formaja: ", 0
	str_osszeghex db "Az eredmeny hexadecimalis formaja: ", 0