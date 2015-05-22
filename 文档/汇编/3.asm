
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

assume cs:code
code segment
    mov ax,cs
    mov ds,ax
    mov ax,0020h
    mov es,ax
    mov bx,0
    mov cx,17h
    s:mov al,[bx]
      inc bx
      loop s
    mov ax,4c00h
    int 21h
    code ends
    end
ret




