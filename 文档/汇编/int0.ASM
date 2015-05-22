assume cs:code
code sgement

start:
	mov ax,cs
	mov ds,ax
	mov si,offset do0

	mov ax,0
	mov es,ax
	mov si,0200h

	mov cx,offset do0end-offset do0
	cld
	rep movsb
	
	mov ax,9
	mov ds,ax
	mov word [0],0200h
	mov word [2],0
	
	mov ax,0ffffh
	mov bh,1
	div bh

	mov ax,4c00h
	int 21h

do0: jmp short do0start
	 db 'divide error!'

do0start:	
	mov ax,cs
    mov ds,ax
	mov si,offset do0
	add si,2
	mov ax,b800h
	mov es,ax
	mov di,160*3+8
	mov cx,13
s:  
	mov al,[si]
	mov ah,2
	mov es:[di],ax
	inc si
	add di,2
loop s	
	mov ax,4c00h
	int 21h

do0end: nop	

code ends
end start

