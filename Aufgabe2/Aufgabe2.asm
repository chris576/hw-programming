org 100h 
cpu 8086

LED equ 0h

firstDis equ 9eh
secondDis equ 9ch
thirdDis equ 9ah
fourthDis equ 98h
fifthDis equ 96h
sixthDis equ 94h
seventhDis equ 92h
eigthDis equ 90h

START: 
    in al, LED
    ; Right Nibble: Zahl in al über eine Maske mit 00001111 laufen lassen.
    ; Left Nibble: Zahl in al um 4 nach rechts verschieben.
    mov cl, al
    mov bl, al
    ; cl right nibble
    and cl, 00001111b ;Right Nibble: Zahl in al über eine Maske mit 00001111 laufen lassen.
    ; bl left nibble
    shr bl, 1
    shr bl, 1
    shr bl, 1
    shr bl, 1
    add cl, bl
    mov al, cl
    out LED, al
    
    mov dl, cl
    and cl, 00001111b
    shr dl, 1
    shr dl, 1
    shr dl, 1
    shr dl, 1
    and dl, 00001111b

    mov al, cl
    mov bx, TAB7
    XLAT
    out secondDis, al

    mov al, dl
    mov bx, TAB7
    XLAT
    out firstDis, al

    jmp START

TAB7 db 63, 48, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 88, 94, 121, 113, 