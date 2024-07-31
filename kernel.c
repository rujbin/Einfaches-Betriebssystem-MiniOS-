void kernel_main(void) {
    const char *str = "Hello, Kernel!";
    char *vidptr = (char*)0xb8000;  // Video-Speicher beginnt bei 0xb8000
    unsigned int i = 0;
    unsigned int j = 0;

    while (str[j] != '\0') {
        vidptr[i] = str[j];  // Zeichen setzen
        vidptr[i+1] = 0x07;  // Attribut-Byte: weißer Text auf schwarzem Hintergrund
        ++j;
        i += 2;
    }

    return;
}
