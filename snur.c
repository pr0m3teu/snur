#include <stdio.h>
#include "snur.h"

bool sn_init(Snur* snur)
{
    snur->items = malloc(sizeof(char) * DEFAULT_SIZE);
    if (snur->items == NULL)
    {
        fprintf(stderr, "[ERROR]: Could not allocate memory for 'Snur'\n");
        return 1;
    }

    snur->size = DEFAULT_SIZE;
    snur->len = 0;
    return 0;
}

static void sn_resize(Snur* snur)
{
    snur->items = realloc(snur->items, snur->size*2);
    if (snur->items == NULL)
    {
        fprintf(stderr, "[ERRORR]: Could not allocate memory for 'Snur'\n");
        exit(1);
    }
    snur->size = snur->size * 2;
}

void sn_append_char(Snur* snur, const char* c)
{
    if (snur->len == snur->size)
    { 
        sn_resize(snur);
    }
    snur->items[snur->len] = c[0];
    snur->len++;
}


