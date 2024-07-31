#ifndef KERNEL_H
#define KERNEL_H

// Funktion zum Ausgeben von Text auf dem Bildschirm
void print_string(const char *str);

// Funktion zum Einlesen von Text (Benutzereingaben) vom Bildschirm
void gets(char *buffer);

// Funktion zum Initialisieren des Bildschirms
void clear_screen();

// Funktion zur Initialisierung der Tastatur (Beispiel, muss implementiert werden)
void init_keyboard();

// Funktion zur Initialisierung der Systemzeit (Beispiel, muss implementiert werden)
void init_timer();

// Funktion zum Initialisieren des Dateisystems (Beispiel, muss implementiert werden)
void init_filesystem();

#endif // KERNEL_H
