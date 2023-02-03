//
// Created by granfelino on 27/01/23.
//

//#include "file_handler.h"
#include <stdio.h>
#include <stdlib.h>

long fill_array(char const *path, char **buffer)
{
    FILE *file;
    int cursor;
    long offset;
    size_t fsize;

    /* open the file and return -1L if file wasn't opened */
    file = fopen(path, "r");
    if (file == NULL) return -1L;

    /* seek the end of the file */
    cursor = fseek(file, 0L, SEEK_END);
    if (cursor != 0) return -1L;

    if ((offset = ftell(file)) < 0) return -1L;
    fsize = (size_t) offset;

    *buffer = malloc(fsize + 1);
    if (buffer == NULL) return -1;

    rewind(file);

}

int main()
{
    return 0;
}