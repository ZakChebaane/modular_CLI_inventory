#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

int main(void) {
    Item items[MAX_ITEMS] = {0};
    int run = 1;
    int count = 0;
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
            add (items, &count, id, name, qty, price);
        } else if (strstr(buffer, "LIST") != NULL) {
            list(items, &count);
        } else if (strstr(buffer, "STOCK") != NULL) {
            strtok(buffer, ",");
            stock(items, &count, strtol(strtok(NULL, ","), NULL, 10), strtol(strtok(NULL, ","), NULL, 10));
        } else if (strstr(buffer, "FIND") != NULL) {
            strtok(buffer, ",");
            find(items, &count, strtol(strtok(NULL, ","), NULL, 10));
        }
    }
    return 0;
}