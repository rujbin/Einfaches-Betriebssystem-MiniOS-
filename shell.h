#ifndef SHELL_H
#define SHELL_H

// Hauptfunktion der Shell
void shell();

// Hilfsfunktionen für die Shell
void print_string(const char *str);
void clear_screen();
void list_files();
void handle_command(const char *command);

#endif // SHELL_H
