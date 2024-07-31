#include "shell.h"
#include "kernel.h" // Für printf, gets, etc.
#include <string.h>

#define MAX_COMMAND_LENGTH 256

// Hilfsfunktionen
static void print_prompt();
static void read_command(char *buffer);
static void execute_command(const char *command);

void shell() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        print_prompt();      // Eingabeaufforderung anzeigen
        read_command(command); // Befehl einlesen
        execute_command(command); // Befehl ausführen
    }
}

// Zeigt die Eingabeaufforderung an
static void print_prompt() {
    print_string("> ");
}

// Liest einen Befehl vom Benutzer ein
static void read_command(char *buffer) {
    // Eingabe vom Benutzer einlesen
    gets(buffer);

    // Entferne abschließendes Leerzeichen und Zeilenumbruch
    size_t length = strlen(buffer);
    if (length > 0 && (buffer[length - 1] == '\n' || buffer[length - 1] == '\r')) {
        buffer[length - 1] = '\0';
    }
}

// Führt den eingegebenen Befehl aus
static void execute_command(const char *command) {
    if (strcmp(command, "help") == 0) {
        print_string("Available commands:\n");
        print_string("help - Show this help message\n");
        print_string("clear - Clear the screen\n");
        print_string("ls - List files in the directory\n");
        print_string("echo <message> - Print the message\n");
        print_string("exit - Exit the shell\n");
    } else if (strcmp(command, "clear") == 0) {
        clear_screen();
    } else if (strncmp(command, "echo ", 5) == 0) {
        print_string(command + 5);
        print_string("\n");
    } else if (strcmp(command, "ls") == 0) {
        list_files();
    } else if (strcmp(command, "exit") == 0) {
        // Hier können wir eventuell die Shell oder das System beenden
        print_string("Exiting shell...\n");
        while (1) {
            // Endlosschleife, um die Shell zu "beenden"
        }
    } else {
        print_string("Unknown command: ");
        print_string(command);
        print_string("\n");
    }
}

// Zeigt eine Beispiel-Dateiliste an
void list_files() {
    print_string("file1.txt\nfile2.txt\nexample.txt\n");
}
