[BITS 16]        ; Wir befinden uns im 16-Bit-Realmodus

; Konstante für Kernel-Speicheradresse
KERNEL_SEGMENT equ 0x1000
KERNEL_OFFSET  equ 0x0000
NUM_SECTORS     equ 2           ; Anzahl der Sektoren zum Laden

start:
    ; Setze das Daten- und Extra-Segment auf 0x07C0
    mov ax, 0x07C0
    add ax, 288         ; Segment + (512 * 9 / 16) = 0x0900
    mov ds, ax
    mov es, ax

    ; Zeige Boot-Nachricht
    mov si, boot_msg
    call print_string

    ; Kernel laden (mehrere Sektoren)
    mov dx, 0x80        ; BIOS-Laufwerksnummer (erste Festplatte)
    mov cx, 0x0002      ; Spur 0, Sektor 2
    mov bx, 0x0000      ; Zieloffset für den Kernel (0x0000)
    
    ; Schleife zum Laden mehrerer Sektoren
    mov ch, 0           ; Spur (erste Spur)
load_sector:
    mov dh, NUM_SECTORS ; Anzahl der Sektoren (hier: 2)
    mov ax, 0x0201      ; BIOS-Funktion 0x02 (Sektor lesen)
    int 0x13            ; BIOS-Interrupt aufrufen
    jc disk_error       ; Fehlerbehandlung, falls das Lesen fehlgeschlagen ist

    ; Springe zu dem geladenen Kernel
    jmp KERNEL_SEGMENT:KERNEL_OFFSET

disk_error:
    ; Fehlermeldung anzeigen
    mov si, error_msg
    call print_string
    ; Fehlercodes anzeigen
    mov si, disk_error_msg
    call print_string
    jmp $               ; Endlosschleife, um Fehler zu melden

print_string:
    mov ah, 0x0E        ; BIOS-TTY-Funktion (Zeichen anzeigen)
.next_char:
    lodsb
    cmp al, 0
    je .done
    int 0x10            ; Zeichen auf dem Bildschirm anzeigen
    jmp .next_char
.done:
    ret

boot_msg db 'Booting OS...', 0
error_msg db 'Disk Error: ', 0
disk_error_msg db 'Check disk and try again.', 0

times 510-($-$$) db 0   ; Fülle den Rest des Bootsektors mit Nullen
dw 0xAA55               ; Boot-Signatur
