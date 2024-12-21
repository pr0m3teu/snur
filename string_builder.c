#include "string_builder.h"

bool sb_init_builder(String_Builder* sb)
{
    sb->items = (char*) malloc(sizeof(char)*DEFAULT_SIZE);
    if (sb->items == NULL)
    {
        fprintf(stderr, "[ERROR]: Could not allocate memory for 'sb_builder'\n");
        return 1;
    }

    strncpy(sb->items, "\0", 1);
    
    sb->count = 0;
    sb->len = 0;
    return 0;
}

void sb_append_char(String_Builder* sb, const char* c)
{
    strncat(sb->items, c, 1);
}
