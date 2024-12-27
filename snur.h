#ifndef SNUR_H_ 
#define SNUR_H_

#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_SIZE 128

typedef struct {
    char *items;
    int len;
    int size;

} Snur;

bool sn_init(Snur* snur);
void sn_append_char(Snur* snur, const char* c);

#endif // STRING_BUILDER_H_
