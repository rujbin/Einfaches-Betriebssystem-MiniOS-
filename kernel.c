#define VIDEO_MEMORY 0xb8000
#define WHITE_ON_BLACK 0x07

void clear_screen() {
    char *vidptr = (char*)VIDEO_MEMORY;
    unsigned int i;
    for (i = 0; i < 80 * 25 * 2; i++) {
        vidptr[i] = ' ';  // Leeren Zeichen
        vidptr[++i] = WHITE_ON_BLACK;  // Attribut-Byte
    }
}

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

void kernel_main(void) {
    clear_screen();  // Bildschirm löschen
    print_string("Hello, Kernel!");

    // Weitere Initialisierungen und Funktionen hier
    while (1) {
        // Endlosschleife
    }
}
