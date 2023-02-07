#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rope.h"
#include "set.h"
#include "file_parse.h"

int main()
{
    // initialize the rope
    rope_part* head = rope_init();

    // initialize the set
    int* first_entry = malloc(sizeof(int)*2);
    first_entry[0] = 0;
    first_entry[1] = 0;
    node* set = set_init(first_entry);

    // create rope structure; structure in form of a list
    for (int i = 0; i < 9; ++i)
    {
        rope_push(head);
    }
    
    // open file; get file pointer;
    FILE *file = file_open("index.txt");

    // initalize variable to stop loop
    int main_loop_break = 0;

    // allocate memory for move info array
    int *move_info = malloc(sizeof(int)*2);

    // main loop
    while (main_loop_break)
    {
        file_yield_move_info(file, move_info);
        move_head(head, move_info[0], move_info[1], set);
    }


    free(move_info);
 	free_rope(head);   
     
	return 0;
}
