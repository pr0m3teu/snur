#ifndef STRING_BUILDER_H_
#define STRING_BUILDER_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 128

typedef struct {
    char *items;
    int len;
    int size;

} String_Builder;

typedef struct {
    char* items;
    int len;
} String_View;

bool sb_init_builder(String_Builder* sb);
void sb_append_char(String_Builder* sb, const char* c);
void sb_to_sv(String_Builder* sb, String_View* sv);

#endif // STRING_BUILDER_H_
