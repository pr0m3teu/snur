#include "string_builder.h"

bool sb_init_builder(sb_builder *sb)
{
    sb->items = (char*) malloc(sizeof(char)*DEFAULT_SIZE);
    if (sb->items == NULL)
    {
        fprintf(stderr, "[ERROR]: Could not allocate memory for 'sb_builder'\n");
        return 1;
    }
    
    sb->count = 0;
    sb->len = 0;
    return 0;
}
