#ifndef STRING_BUILDER_H_
#define STRING_BUILDER_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 128

typedef struct {
    char *items;
    int len;
    int count;

} sb_builder;

bool sb_init_builder(sb_builder *sb);

#endif // STRING_BUILDER_H_
