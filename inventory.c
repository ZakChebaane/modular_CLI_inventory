#include "inventory.h"
#include <stdio.h>

void add (int id, char *name, int qty, double price) {
    printf("%d\n%s\n%d\n%lf\n", id, name, qty, price);
}
