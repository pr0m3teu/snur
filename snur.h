#ifndef SNUR_H_ 
#define SNUR_H_

#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_SIZE 128

typedef struct {
    char *items;
    size_t len;
    size_t size;
} Snur;

typedef struct {
    char *items;
    size_t len;
} Snur_View;

bool sn_init(Snur* snur);
void sn_append_char(Snur* snur, const char* c);
void sn_append_many(Snur* snur, const char* str, size_t len);
void sn_append_cstr(Snur* snur, const char* cstr);
void sn_append_null(Snur* snur);
void sn_remove_null(Snur* snur);
Snur_View sn_build_snur(Snur snur);



#endif // STRING_BUILDER_H_
