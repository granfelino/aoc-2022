//
// Created by granfelino on 27/01/23.
//

#include "file_handler.h"
#include <stdio.h>
#include <stdlib.h>


char* read_f(char* arr, int* size, FILE* file)
{
    file = fopen("input.txt", "rb");
    if (!file) fclose(file), perror("file not read");

    long lSize;
    char* buffer;

    fseek(file, 0, SEEK_END);
    lSize = ftell(file);
    rewind(file);

    buffer = calloc(sizeof(char), lSize+1);
    if (!buffer)
    {
        fclose(file);
        fputs("lack of memory for char array\n", stderr);
        exit(1);
    }

    if (fread(buffer, lSize+1, 1, file) != lSize+1)
    {
        fclose(file);
        fputs("error reading a file into the array", stderr);
        exit(1);
    }

    if(EOF == fclose(file))
    {
        free(buffer);
    }

}

int main()
{
    FILE* file = file_open("../input.txt");
    read_f(file);
}