#include "kernel.h"
#include <string.h>

#define MAX_COMMAND_LENGTH 256

void shell();

void shell() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        print_string("> ");
        
        // Befehl vom Benutzer einlesen
        gets(command);
        
        // Befehl verarbeiten
        if (strcmp(command, "help") == 0) {
            print_string("Available commands: help, clear, ls, echo\n");
        } else if (strcmp(command, "clear") == 0) {
            clear_screen();
        } else if (strncmp(command, "echo ", 5) == 0) {
            print_string(command + 5);
            print_string("\n");
        } else if (strcmp(command, "ls") == 0) {
            list_files();
        } else {
            print_string("Unknown command: ");
            print_string(command);
            print_string("\n");
        }
    }
}

void list_files() {
    print_string("file1.txt\nfile2.txt\nexample.txt\n");
}
