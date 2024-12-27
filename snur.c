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

void sn_append_many(Snur* snur, const char* str, size_t len)
{
    if (snur->len + len >= snur->size)
    {
        sn_resize(snur);
    }

    for (size_t i = 0; i < len; ++i)
    {
        snur->items[snur->len + i] = str[i];
    }
    snur->len += len;
}

void sn_append_cstr(Snur* snur, const char* cstr)
{
    size_t len = 0;
    while (cstr[len] != '\0')
    {
        len++;
    }

    sn_append_many(snur, cstr, len);
}

void sn_append_null(Snur* snur)
{
    if (snur->len + 1 > snur->size) sn_resize(snur);

    snur->items[snur->len++] = '\0';
}

void sn_remove_null(Snur* snur)
{
    if (snur->items[snur->len - 1] == '\0') snur->len--;
}

Snur_View sn_build_snur(Snur snur)
{
    Snur_View sn = {0};
    sn.items = malloc(sizeof(char)*snur.len);
    for (size_t i = 0; i < snur.len; i++)
    {
        sn.items[i] = snur.items[i];
    }
    sn.items[snur.len] = '\0';
    sn.len = snur.len - 1;
    return sn; 
}
