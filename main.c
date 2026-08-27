#include <stdio.h>
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
            char *id = strtok(NULL, ",");
            char *name = strtok(NULL, ",");
            char *qty = strtok(NULL, ",");
            char *price = strtok(NULL, ",");
            add (id, name, qty, price);
        }
    }
    return 0;
}