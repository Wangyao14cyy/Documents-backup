
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,5
mov bx,10
add ax,bx
sub ax,1
hlt

ret




