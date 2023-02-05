//
// Created by granik on 2023-02-05.
//
#include <stdio.h>
#include <stdlib.h>

int get_direction(char dir)
{
    if (dir == 'U') return 0;
    else if (dir == 'R') return 1;
    else if (dir == 'D') return 2;
    else if (dir == 'L') return 3;
    else
    {
        fprintf(stderr, "Undefined character passed to get_direction() at: ", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
}

FILE* file_open(char* const path)
{
    // open file and set it to a static pointer
    static FILE *file = NULL;
    if (file == NULL) file = fopen(path, "r");

    // if opening the file fails return failure
    if (file == NULL)
    {
        fprintf(stderr, "fopen failed to open the file at: ", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    return file;
}

void file_close(FILE *file)
{
    if (fclose(file) == EOF)
    {
        fprintf(stderr, "fclose() failed to close the file at: ", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    else
    {
        puts("file closed\n");
    }
}


void file_yield_move_info(FILE *file, int *file_move_info)
{
    // define variables
//  int file_move_info[]; // it gets initalized down the function
    int file_string_size;
    char c;
    fpos_t *file_string_starting_position;

    // initialize variables
    file_string_size = 0;
    c = getc(file);

    // get file starting position to rewind to; exit if fails
    if (fgetpos(file, file_string_starting_position) != 0)
    {
        fprintf(stderr, "fgetpos() failed to get position at: ", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // count chars in the string
    while ( (c != '\n') || (c != EOF) )
    {
        ++file_string_size;
        c = getc(file);
    }

    // set the file to the starting position; exit if fails
    if (fsetpos(file, file_string_starting_position) != 0)
    {
        fprintf(stderr, "fsetpos() failed to set position to initial at: ", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }


    // populate the file_move_info[], depending on the string size (i.e. if number of steps is a one-digit or a two-digit number)
    if (file_string_size == 3)
    {
        for (int i = 0; i < file_string_size; ++i)
        {
            c = getc(file);
            if (i == 0) file_move_info[0] = get_direction(c);
            if (i == 2) file_move_info[1] = c - '0';
        }
    }
    else
    {
        for (int i = 0; i < file_string_size; ++i)
        {
            c = getc(file);
            if (i == 0) file_move_info[0] = get_direction(c);
            if (i == 2) file_move_info[1] += (10 * (c - '0'));
            if (i == 3) file_move_info[1] += (c - '0');
        }
    }

}




int main()
{
    int *move_info = malloc(sizeof(int)*2);
    FILE *file = file_open("input.txt");

    file_yield_move_info(file, move_info);

    file_close(file);

    printf("yielded move info is (%d, %d)\n", move_info[0], move_info[1]);

    return 0;
}