; boot.asm
[BITS 16]       ; Wir befinden uns im 16-Bit-Realmodus

start:
    mov ax, 0x07C0      ; Setze Segmentregister
    add ax, 288         ; 0x07C0 + (512 * 9 / 16) = 0x0900
    mov ds, ax
    mov es, ax

    mov si, boot_msg
    call print_string

    ; Lade den Kernel in den Speicher (ab 0x1000:0x0000)
    mov bx, 0x0000      ; Zieloffset für den Kernel (0x0000)
    mov dh, 1           ; Anzahl der Sektoren (hier: 1)
    mov dl, 0x80        ; BIOS-Laufwerksnummer (erste Festplatte)
    mov cx, 0x0002      ; Spur 0, Sektor 2
    mov ax, 0x0201      ; BIOS-Funktion 0x02 (Sektor lesen)
    int 0x13            ; BIOS-Interrupt aufrufen

    jc disk_error       ; Fehlerbehandlung

    ; Springe zu dem geladenen Kernel
    jmp 0x1000:0000     ; Seg:Offset-Adresse des geladenen Kernels

disk_error:
    mov si, error_msg
    call print_string
    jmp $

print_string:
    mov ah, 0x0E        ; BIOS-TTY-Funktion (Zeichen anzeigen)
.next_char:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .next_char
.done:
    ret

boot_msg db 'Booting OS...', 0
error_msg db 'Disk Error', 0

times 510-($-$$) db 0   ; Fülle den Rest des Bootsektors mit Nullen
dw 0xAA55               ; Boot-Signatur
