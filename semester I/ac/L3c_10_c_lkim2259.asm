;[azok a karakterek A-ból, amelyek ASCII kód szerint az A utolsó és a B utolsó karaktere közt vannak (azaz, amelyekre A[utolsó] < A[i] < B[utolsó])
;(pl. A="abmnxd", B="prst" =>"mn")] + [karakterpárokra osztjuk a B-t, az első párban a két karaktert abc sorrendbe tesszük (ASCII kód szerint),
;a másodikban fordított abc sorrendbe, majd újra abc sorrendbe, ... Ha az utolsó karakternek nincs párja, akkor marad ahogy volt (pl. baxycdu => abyxcdu)].
;A és B csak betűket tartalmaz, más karaktereket nem kell lekezelni.


%include 'mio.inc'
%include 'io.inc'
global main

section .text

read_str_c:  ;beolvas edi memoriacimre egy stringet
	push eax
	push ecx
	push edx
	
	xor edx, edx
	xor eax, eax
	xor ecx, ecx
	
  .readchar:
	
	call 	mio_readchar
	
	;megallasi feltetel
	cmp 	al, 13
	je 		.end
	
	call 	mio_writechar
	
	;memoriaba iras
	mov 	[edi + ecx], al
	inc 	ecx
	jmp 	.readchar

  .end: 
	mov [edi + ecx], dl
	pop edx
	pop ecx
	pop eax
	ret 
	
write_str_c: ; kiirja az edi memoriacimen levo stringet
	pusha
	xor edx, edx
	xor ecx, ecx
	.writechar:
	
	cmp 	[edi + ecx], dl;megallasi feltetel, vagyis ameddig 0s karakter nem lesz
	je		.end
	
	mov 	al, [edi + ecx]
	inc 	ecx
	call 	mio_writechar
	
	jmp		.writechar

  .end:
	popa
	ret

kiment_karakterek:;kimenti azon karaktereket az esi memoriacimre, amelyek az a-ban vannak, a utolso karaktenel nagyobbak de b utolso karakterenel kisebbek
	pusha
	xor edx, edx
	xor ebx, ebx
	mov edi, str_a
	
	xor eax, eax
	xor ecx, ecx
	.folytat_a:; addig megyunk el az a stringben ameddig 0-t nem talalunk
	cmp [edi + ecx], al
	je .vege_a
	mov dl, [edi + ecx]
	inc ecx
	jmp .folytat_a
	.vege_a:
	
	xor eax, eax	

	mov edi, str_b
	xor ecx, ecx
	
	.folytat_b:; ugy szinten a b-nel is
	cmp [edi + ecx], al
	je .vege_b
	mov bl, [edi + ecx]
	inc ecx
	jmp .folytat_b
	.vege_b:
	
	xor eax, eax
	xor ecx, ecx

	mov edi, str_a
	mov ecx, -1
	
	
	.masol:; az eaxedik poziciora beteszzuk az a-nak az elemet ha megfelel a felteteleknek
	inc ecx
	push eax
	xor eax, eax
	cmp [edi + ecx], al
	je .vege
	pop eax
	
	cmp [edi + ecx], dl
	jle .masol
	cmp [edi + ecx], bl
	jge .masol
	push ebx
	mov bl, [edi + ecx]
	mov [esi + eax], bl
	inc eax
	pop ebx
	jmp .masol
	.vege:
	pop eax
	xor edx, edx
	mov [esi + ecx], dl; elmentjuk a karakterlanc vegere a 0-s karaktert
	popa
	ret
	
b_fordit:; az esi memoriacim kovetkezo cimeire bemasoljuk a b elemeit a szabaly szerint
	mov edi, str_b 
	xor ecx, ecx
	xor eax, eax
	xor ebx, ebx
	xor edx, edx
	
	.folytatas:; megkeressuk az esi memoriacim azon eltolasat, ahol 0 van
	cmp [esi + ecx], dl
	je .veg
	inc ecx
	jmp .folytatas
	.veg:
	cmp ecx, 0
	mov ebx, ecx
	
	xor ecx, ecx
	.folytatas2:; megkeressuk az edi hosszat, ugy, hogy megallapitjuk hogy hol van a 0 karakter
	cmp [edi + ecx], dl
	je .veg2
	inc ecx
	jmp .folytatas2
	.veg2:
	
	dec ecx
	
	dec ebx
	mov eax, ecx
	mov ecx, -1
	

	.ismetel:
	cmp ecx, eax; mivel az eax-ben megvan mar az elozo reszbol a b-nek a hossza, ezert eddig megyunk el a ciklussal
	je .vege_fordit
	inc ecx
	inc ebx
	mov dl, [edi + ecx]
	cmp ecx, eax
	je .paratlan
	push eax
	inc ecx
	inc ebx
	mov al, [edi + ecx]
	cmp al, dl
	jge .nemCsere
	xchg eax, edx; beallitja hogy alfabetikus sorrendben legyen
	.nemCsere:
	
	
	push ecx
	mov ecx, [seged]; a segedet aszerint valtoztatjuk hogy meg kell-e forditani a karakterpart vagy sem
	cmp ecx, 0
	je .nemForditott
	xchg al, dl
	mov [esi + ebx - 1], al; megforditja a sorrendet
	mov [esi + ebx], dl
	mov ecx, 0
	mov [seged], ecx
	pop ecx
	pop eax
	jmp .ismetel
	.nemForditott:
	mov [esi + ebx - 1], al
	mov [esi + ebx], dl
	mov ecx, 1
	mov [seged], ecx
	pop ecx
	pop eax
	jmp .ismetel
	

	.paratlan:
	mov [esi + ebx], dl; ha paratlan a hossza akkor hozzaadjuk az egyedul maradt karaktert a vegehez
	inc ebx
	.vege_fordit:
	xor eax, eax
	inc ebx
	mov [esi + ebx], al

ret
	
	
main:
	mov edi, str_a
	call read_str_c
	call mio_writeln
	
	mov edi, str_b
	call read_str_c
	call mio_writeln
	
	mov esi, str_c
	call kiment_karakterek
	mov edi, str_c
	
	
	mov esi, str_c
	call b_fordit
	mov edi, str_c
	call write_str_c

ret
section .data
fordit dd 0
seged dd 1

section .bss
str_a resb 256
str_b resb 256
str_c resb 256
