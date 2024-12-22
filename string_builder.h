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

bool sb_init_builder(String_Builder* sb);
void sb_append_char(String_Builder* sb, const char* c);


#endif // STRING_BUILDER_H_
