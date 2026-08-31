#include "inventory.h"
#include <stdio.h>
#include <string.h>

static int checkID (Item *items, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (items[i].id == id) {
            return 0;
        }
    }
    return 1;
}
void add (Item *items, int *count, int id, char *name, int qty, double price) {
    if (checkID(items, count, id) == 0) {
        printf("[FAILED] Already exists (ID: %d)\n", id);
        return;
    }
    items[*count].id = id;
    strncpy(items[*count].name, name, NAME_LEN);
    items[*count].qty = qty;
    items[*count].price = price;
    printf("[SUCCESS] Added %s (ID: %d)\n", items[*count].name, items[*count].id);
    *count += 1;
}
void list (Item *items, int *count) {
    // Lists out the items
    printf("ID    NAME             QTY    PRICE   \n");
    printf("--------------------------------------\n");
    for (int i = 0; i < *count; i++) {
        printf("%d   %s          %d         %.1lf  \n", items[i].id, items[i].name, items[i].qty, items[i].price);
    }
}
void stock (Item *items, int *count, int id, int newQty) {
    for (int i = 0; i < *count; i++) {
        if (items[i].id == id) {
            items[i].qty = newQty;
            printf("[SUCCESS] %s stock updated to: %d\n", items[i].name, items[i].qty);
            return;
        }
    }
    printf("[FAILED] (ID:%d) does not exist\n", id);
}

// ADD,101,Apples,2,2.50
// ADD,102,Oranges,4,3.75