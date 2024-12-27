#include <stdio.h>
#include "snur.h"

int main(void)
{
    Snur snur = {0};
    sn_init(&snur);
    
    sn_append_many(&snur, "Hello ", 6);
    sn_append_cstr(&snur, "World!");
    sn_append_char(&snur, "\n");
    sn_append_null(&snur);
    printf("%s", snur.items);
    return 0;
}
