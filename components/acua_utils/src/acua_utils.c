#include "acua_utils.h"
#include <stdio.h>
#include <stdlib.h>

void utils_free_ptr(void ** ptr){
    if (ptr == NULL || *ptr == NULL)
        return;

    free(*ptr);
    *ptr = NULL;
}