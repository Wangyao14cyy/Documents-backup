assume cs:code

code segment

start:
	mov ax,cs
	mov ds,ax
	mov si,offset do

	mov ax,0
	mov es,ax
	mov di,0200h

	mov cx,offset doend-offset do
	cld
	rep movsb
	
	mov word ptr es:[0],0200h
	mov word ptr es:[2],0
	
	mov ax,0ffffh
	mov bh,1
	div bh

	mov ax,4c00h
	int 21h

do: jmp short dostart
	 db 'divide error!'

dostart:	
	mov ax,csjn 7
    mov ds,ax
	mov si,202h
	mov ax,0b800h
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

doend: nop	

code ends
end start

