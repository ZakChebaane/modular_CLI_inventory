#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

int main(void) {
    int run = 1;
    while (run) {
        char buffer[48];
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "EXIT") == 0) {
            run = 0;
            printf("Goodbye.");
        } else if (strstr(buffer, "ADD") != NULL) {
            char *token = strtok(buffer, ",");
            int id = strtol(strtok(NULL, ","), NULL, 10);
            char *name = strtok(NULL, ",");
            int qty = strtol(strtok(NULL, ","), NULL, 10);
            double price = strtod((strtok(NULL, ",")), NULL);
            add (id, name, qty, price);
        }
    }
    return 0;
}