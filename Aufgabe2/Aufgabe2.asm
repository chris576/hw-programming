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
    sar bl, 1
    sar bl, 1
    sar bl, 1
    sar bl, 1
    and bl, 00001111b
    add cl, bl
    mov al, cl
    out LED, al
    mov al, [TAB7]
    out firstDis, al
    jmp START

TAB7 db 00111111b, 01100000b, 11011010b, 11110010b, 01100110b, 10110110b, 10111110b, 11100000b, 11111110b, 11110110b, 11110110b, 00111110b, 10011100b, 01111010b, 10011110b, 10001110b
