#include "keyboard.h"

#define KEYBOARD_PORT 0x60

void keyboard_handler() {
    unsigned char scancode = inportb(KEYBOARD_PORT);
    // Verarbeiten Sie den Scancode
}

void init_keyboard() {
    // Tastatur-Interrupt initialisieren
}
