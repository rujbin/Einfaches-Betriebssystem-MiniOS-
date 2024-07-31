#include "filesystem.h"

#define MAX_FILES 128

typedef struct {
    char name[32];
    int size;
    int start_block;
} File;

File file_table[MAX_FILES];

void init_filesystem() {
    // Initialisieren Sie das Dateisystem
}

void create_file(const char *name) {
    // Datei erstellen
}

void delete_file(const char *name) {
    // Datei löschen
}

void list_files() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_table[i].name[0] != '\0') {
            printf("%s\n", file_table[i].name);
        }
    }
}
