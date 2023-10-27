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
    add cl, bl
    add bl, cl
    mov al, cl
    out LED, al
    mov al, bl
    out firstDis, al
    jmp START