#include "kernel.h"

#define VIDEO_MEMORY 0xb8000
#define WHITE_ON_BLACK 0x07

// Gibt einen String auf dem Bildschirm aus
void print_string(const char *str) {
    char *vidptr = (char*)VIDEO_MEMORY;
    unsigned int i = 0;

    while (*str != '\0') {
        vidptr[i] = *str;       // Zeichen setzen
        vidptr[i + 1] = WHITE_ON_BLACK; // Attribut-Byte
        ++str;
        i += 2;
    }
}

// Liest eine Zeile von der Konsole ein (rudimentäre Implementierung)
void gets(char *buffer) {
    char *vidptr = (char*)VIDEO_MEMORY;
    unsigned int i = 0;
    char c;

    while (1) {
        c = vidptr[i];  // Simuliere die Tastatureingabe (in der Realität müssen Sie einen Tastatureingabepuffer verwenden)
        if (c == '\r') {  // Enter-Taste
            buffer[i] = '\0';
            break;
        } else if (c == '\b') {  // Backspace-Taste
            if (i > 0) {
                --i;
                buffer[i] = '\0';
                vidptr[i * 2] = ' ';
                vidptr[i * 2 + 1] = WHITE_ON_BLACK;
            }
        } else if (c >= ' ' && c <= '~') {  // Nur druckbare Zeichen
            buffer[i] = c;
            vidptr[i * 2] = c;
            vidptr[i * 2 + 1] = WHITE_ON_BLACK;
            ++i;
        }
    }
}

// Löscht den Bildschirm
void clear_screen() {
    char *vidptr = (char*)VIDEO_MEMORY;
    unsigned int i;
    for (i = 0; i < 80 * 25 * 2; i++) {
        vidptr[i] = ' ';  // Leeren Zeichen
        vidptr[++i] = WHITE_ON_BLACK;  // Attribut-Byte
    }
}

// Weitere Initialisierungsfunktionen könnten hier hinzugefügt werden
void init_keyboard() {
    // Beispielhafte Initialisierung der Tastatur
}

void init_timer() {
    // Beispielhafte Initialisierung des Timers
}

void init_filesystem() {
    // Beispielhafte Initialisierung des Dateisystems
}

// Hauptfunktion des Kernels
void kernel_main(void) {
    clear_screen();  // Bildschirm löschen
    print_string("Welcome to MiniOS!\n");

    // Hier könnte der Shell-Start oder andere Initialisierungen kommen
    shell(); // Startet die Shell

    while (1) {
        // Endlosschleife, da die Shell bereits im Endlosschleifen-Modus ist
    }
}
