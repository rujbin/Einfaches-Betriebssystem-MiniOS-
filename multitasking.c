#include "multitasking.h"

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    void (*entry_point)();
    // Weitere Prozessinformationen
} Process;

Process process_table[MAX_PROCESSES];

void init_multitasking() {
    // Multitasking initialisieren
}

void create_process(void (*entry_point)()) {
    // Prozess erstellen
}

void switch_task() {
    // Prozess wechseln
}
