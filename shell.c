#include "kernel.h" // Kernel-Funktionen und Systemaufrufe

void shell() {
    char command[256];
    
    while (1) {
        printf("> ");
        gets(command);
        
        if (strcmp(command, "help") == 0) {
            printf("Available commands: help, clear, ls, echo\n");
        } else if (strcmp(command, "clear") == 0) {
            clear_screen();
        } else if (strncmp(command, "echo ", 5) == 0) {
            printf("%s\n", command + 5);
        } else if (strcmp(command, "ls") == 0) {
            list_files();
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
}
