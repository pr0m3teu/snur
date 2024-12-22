#include "string_builder.h"

bool sb_init_builder(String_Builder* sb)
{
    sb->items = malloc(sizeof(char) * DEFAULT_SIZE);
    if (sb->items == NULL)
    {
        fprintf(stderr, "[ERROR]: Could not allocate memory for 'String_Builder'\n");
        return 1;
    }

    sb->size = DEFAULT_SIZE;
    sb->len = 0;
    return 0;
}

static void resize(String_Builder* sb)
{
    sb->items = realloc(sb, sb->size*2);
    if (sb->items == NULL)
    {
        fprintf(stderr, "[ERRORR]: Could not allocate memory for 'String_Builder'\n");
        exit(1);
    }
    sb->size = sb->size * 2;
}

void sb_append_char(String_Builder* sb, const char* c)
{
    if (sb->len == sb->size)
    { 
        resize(sb);
    }
    sb->items[sb->len] = c[0];
    sb->len++;
}

void sb_to_sv(String_Builder* sb, String_View* sv)
{
    if (sb == NULL || sv == NULL) return;
    sv->len = sb->len;
    sv->items = malloc(sizeof(char) * sv->len);
    for (int i = 0; i < sv->len; ++i)
    {
        sv->items[i] = sb->items[i];
    }
}

