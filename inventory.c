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
    *count += 1;
    printf("%d %s %d %lf\n", items[0].id, items[0].name, items[0].qty, items[0].price);
    printf("%d %s %d %lf\n", items[1].id, items[1].name, items[1].qty, items[1].price);
}
