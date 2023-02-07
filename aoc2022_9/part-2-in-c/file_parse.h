//
// Created by granik on 2023-02-07.
//

#ifndef PART_2_IN_C_FILE_PARSER_H
#define PART_2_IN_C_FILE_PARSER_H

#include <stdio.h>
#include <stdlib.h>

int get_direction(char dir);
FILE* file_open(char* const path);
void file_close(FILE *file);
void file_yield_move_info(FILE *file, int *file_move_info, int *main_loop_break);

#endif //PART_2_IN_C_FILE_PARSER_H
