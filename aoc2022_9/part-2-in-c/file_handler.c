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

    // set the offset of the end of the file to offset var; if not return -1; if yes assign it to fsize and cast as size_t
    if ((offset = ftell(file)) < 0) return -1L;
    fsize = (size_t) offset;

    // allocate the space of size fsize + 1 to the buffer; + 1 for the null string termination
    *buffer = malloc(fsize + 1);
    if (buffer == NULL) return -1;

    // rewind cursor to the beginning of the file
    rewind(file);

    // fill the buffer with the file contents
    if (fread(*buffer, 1, fsize, file) != fsize)
    {
        free(*buffer);
        return -1L;
    }

    // close file; or if it returns EOF that means that an error has come up
    if (fclose(file) == EOF)
    {
        free(*buffer);
        return -1L;
    }

    // make sure the buffer is null-terminated
    (*buffer)[fsize] = '\0';

    // return file size
    return (long) fsize;


}


void print_file(const char* path)
{
    FILE *file = fopen(path, "r");
    if (file == NULL) EXIT_FAILURE;

    char c = getc(file);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(file);
    }
    fclose(file);
}

int main()
{
//    char *buffer;
//
//    long size = fill_array("input.txt", &buffer);
//
//    for (int i = 0; i < size; ++i) printf("%c", buffer[i]);

    print_file("input.txt");
    return 0;
}