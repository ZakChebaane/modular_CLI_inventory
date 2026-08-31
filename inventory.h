#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEMS 50
#define NAME_LEN 32

typedef struct {
    double price;
    int id;
    int qty;
    char name[NAME_LEN];
} Item;

void add (Item *items, int *count, int id, char *name, int qty, double price);
void list (Item *items, int *count);
void stock (Item *items, int *count, int id, int newQty);
void find (Item *items, int *count, int id);

#endif