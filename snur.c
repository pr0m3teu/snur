#include <string.h>
#include <stdio.h>
#include "snur.h"

void sn_init(Snur* snur)
{
    snur->items = malloc(sizeof(char) * DEFAULT_SIZE);
    if (snur->items == NULL)
    {
        fprintf(stderr, "[ERROR]: Could not allocate memory for 'Snur'\n");
        exit(1);
    }

    snur->size = DEFAULT_SIZE;
    snur->len = 0;
}

void sn_from_cstr(Snur* snur, const char* cstr)
{
    size_t len = strlen(cstr);
   snur->items = malloc(sizeof(char) * len);
   if (snur->items == NULL)
   {
       fprintf(stderr, "[ERROR]: Could not allocate memory for 'Snur'\n");
       exit(1);
   }
   snur->len = len;
   snur->size = len;
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

void sn_append_char(Snur* snur, const char* ch)
{
    if (snur->len == snur->size)
    { 
        sn_resize(snur);
    }
    snur->items[snur->len] = ch[0];
    snur->len++;
}

void sn_append_many(Snur* snur, const char* str, size_t len)
{
    if (snur->len + len >= snur->size)
    {
        sn_resize(snur);
    }

//    for (size_t i = 0; i < len; ++i)
//    {
//        snur->items[snur->len + i] = str[i];
//    }

    strncpy(snur->items + snur->len, (char*)str, len);
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

char sn_pop_char(Snur* snur)
{
    return snur->items[snur->len--];
}

Snur_View sn_build_snur(Snur snur)
{
    Snur_View sn = {0};
    sn.items = malloc(sizeof(char )* snur.len);
    //for (size_t i = 0; i < snur.len; i++)
    //{
    //    sn.items[i] = snur.items[i];
    //}
    strncpy(sn.items, snur.items, snur.len);
    sn.items[snur.len] = '\0';
    sn.len = snur.len;
    return sn; 
}
