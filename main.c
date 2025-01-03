#include <stdio.h>
#include <stdlib.h>
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
    
    Snur_View sn = sn_build_snur(snur);
    printf("%s", sn.items);
    
    sn_pop_char(&snur);
    sn_append_cstr(&snur, "Hello again\n");
    sn_append_null(&snur);

    free(snur.items);
    snur.items = NULL;
    printf("%s", sn.items);

    free(sn.items);
    return 0;
}
