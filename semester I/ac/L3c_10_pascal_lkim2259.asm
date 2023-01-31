;[azok a karakterek A-ból, amelyek ASCII kód szerint az A utolsó és a B utolsó karaktere közt vannak (azaz, amelyekre A[utolsó] < A[i] < B[utolsó])
;(pl. A="abmnxd", B="prst" =>"mn")] + [karakterpárokra osztjuk a B-t, az első párban a két karaktert abc sorrendbe tesszük (ASCII kód szerint),
;a másodikban fordított abc sorrendbe, majd újra abc sorrendbe, ... Ha az utolsó karakternek nincs párja, akkor marad ahogy volt (pl. baxycdu => abyxcdu)].
;A és B csak betűket tartalmaz, más karaktereket nem kell lekezelni.


%include 'mio.inc'
%include 'io.inc'
global main

section .text

read_str_pascal:  ;reads a string to the memory tag stored in edi
	push eax
	push ecx
	
	xor eax, eax
	xor ecx, ecx
	
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
	mov [edi], cl; mivel a legelso biten a hossz-t taroljuk, ezert ezt betesszuk az [edi] memoriacimre
	pop ecx
	pop eax
	ret 
	
write_str_pascal: ;writes a string starting from the memory tag stored in edi
	pusha
	
	xor 	cl, cl
	mov 	cl, [edi]; itt van meg a karakterlanc hossza
	
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

kiment_karakterek:
	pusha; mindent kimentunk a verembe
	xor edx, edx
	xor ebx, ebx
	mov edi, str_a
	
	xor eax, eax
	mov al, [edi]
	mov dl, [edi + eax]; az a-nak az utolso eleme
	
	mov edi, str_b
	xor eax, eax
	mov al, [edi]
	mov bl, [edi + eax]; a b-nek az utolso eleme
	
	xor eax, eax
	xor ecx, ecx

	mov edi, str_a
	
	
	.masol:
	inc ecx
	cmp cl, [edi]
	je .vege

	cmp [edi + ecx], dl
	jle .masol
	cmp [edi + ecx], bl
	jge .masol
	inc eax
	push ebx; ide csak akkor er el a fuggveny ha a[utolso] < a[i] < b[utolso]
	mov bl, [edi + ecx]
	mov [esi + eax], bl
	pop ebx
	jmp .masol
	.vege:
	mov [esi], al; frissitjuk az esi hosszat
	popa
	ret
	
b_fordit:
	mov edi, str_b 
	xor ecx, ecx
	xor eax, eax
	xor ebx, ebx
	xor edx, edx
	
	mov al, [edi]; a b-nek a hossza
	mov bl, [esi]; az esi memoriacimen tarolt karakaterlanc hossza
	

	.ismetel:
	cmp ecx, eax
	je .vege_fordit
	inc ecx
	mov dl, [edi + ecx]; az edx-ben lesznek a 2k+1 indexu karakterek
	inc ebx
	cmp ecx, eax
	je .paratlan
	inc ecx
	inc ebx
	push eax
	mov al, [edi + ecx]; ha paros hosszu, akkor ide mindig elmenti a 2k-adik karakter
	cmp al, dl
	jge .nemCsere
	xchg eax, edx
	.nemCsere:
	push ecx
	mov ecx, [seged]; a seged valtozo erteketol fuggoen forditjuk meg vagy nem a karakterek sorrendjet
	cmp ecx, 0
	je .nemForditott
	xchg al, dl
	mov [esi + ebx - 1], al
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
	mov [esi + ebx], dl; ha paratlan hosszu a karakterlanc, az utolso elemet hozzaadja az esi-nek a megfelelo cimere
	.vege_fordit:
	mov [esi], bl

ret
	
	
main:
	mov edi, str_a
	call read_str_pascal
	call mio_writeln
	
	mov edi, str_b
	call read_str_pascal
	call mio_writeln
	
	mov esi, str_c
	call kiment_karakterek
	
	mov esi, str_c
	call b_fordit
	mov edi, str_c
	call write_str_pascal

ret
section .data
fordit dd 0
seged dd 1

section .bss
str_a resb 256
str_b resb 256
str_c resb 256
