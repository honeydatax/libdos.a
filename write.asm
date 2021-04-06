org 0x100
mov ax,3
int 0x10
mov al,1
mov ah,0x3d
mov dx,fname
int 0x21
mov bx,0
mov dx,outputs
mov cx,13
mov ah,0x40
int 0x21
mov ax,0x4c00
int 0x21
fname db 'CON',0
outputs db 'hello world',13,10,0
