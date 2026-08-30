#include "inventory.h"
#include <stdio.h>
#include <string.h>

void add (Item *items, int *count, int id, char *name, int qty, double price) {
    items[*count].id = id;
    strncpy(items[*count].name, name, NAME_LEN);
    items[*count].qty = qty;
    items[*count].price = price;
    *count += 1;
    printf("%d %s %d %lf\n", items[0].id, items[0].name, items[0].qty, items[0].price);
    printf("%d %s %d %lf\n", items[1].id, items[1].name, items[1].qty, items[1].price);
}
