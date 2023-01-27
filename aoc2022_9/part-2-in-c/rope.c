#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

// DEFINING A ROPE PART AND ALL THE FUNCTIONS TO MOVE THE BODY PARTS
typedef struct rope_part rope_part;

struct rope_part
{
	rope_part* prev_part;
	rope_part* next_part;
	int position[2];
};


// FILL OFFSET ARRAY INT[2] IN RELATION TO THE ROPE PART AHEAD
void get_offset(int* buf, rope_part* part, rope_part* prev)
{
	int x = prev->position[0] - part->position[0];
	int y = prev->position[1] - part->position[1];
	buf[0] = x;
	buf[1] = y;
	printf("\n\nprevious' position: %d, %d\ncurrent part position: %d, %d\n",
	prev->position[0], prev->position[1], part->position[0], part->position[1]);
	printf("calculated offset is: %d, %d\n\n", x, y);
}


// MOVE THE INNER PART OF THE ROPE BASED ON THE OFFSET IT HAS TO THE PART AHEAD
void move_inner_rope_part(rope_part* part, node* set_ptr)
{
	int offset[2];
	get_offset(offset, part, part->prev_part);
	

    if (abs(offset[0]) <= 1 && abs(offset[1]) <= 1)
    {
        // no movement
        return;
    }
    else if (offset[0] == 0 || offset[1] == 0)
    {
        // horizontal/vertical movement

        if (offset[0] == 0)
        {
            // vertical

            if (offset[1] > 0)
                ++part->position[1]; // up
            else
                --part->position[1]; // down
        }
        else
        {
            // horizontal

            if (offset[0] > 0)
                ++part->position[0]; // right
            else
                --part->position[0]; // left
        }
    }
    else
    {
        // assert that offset is between (-2 and -1) and (1, 2) on both axes

        assert(abs(offset[0]) >= 1);
        assert(abs(offset[0]) <= 2);

        assert(abs(offset[1]) >= 1);
        assert(abs(offset[1]) <= 2);

        // left upper
        if (offset[0] < 0 && offset[1] > 0)
        {
            --part->position[0];
            ++part->position[1];
        }

        // right upper
        else if (offset[0] > 0 && offset[1] > 0)
        {
            ++part->position[0];
            ++part->position[1];
        }

        // right lower
        else if (offset[0] > 0 && offset[1] < 0)
        {
            ++part->position[0];
            --part->position[1];
        }

        // left lower
        else if (offset[0] < 0 && offset[1] < 0)
        {
            --part->position[0];
            --part->position[1];
        }
    }
    printf("body part moved; position: %d, %d\n", part->position[0], part->position[1]);

    // MOVE THE NEXT ROPE PART IF IT EXISTS
    if (part->next_part != NULL)
    {
        move_inner_rope_part(part->next_part, set_ptr);
    }
    else
    {
        printf("tail position changed to: %d, %d\n", part->position[0], part->position[1]);
        set_push(set_ptr, part->position);
    }
}


// MOVE THE HEAD WHICH THEN WILL MOVE THE NEXT ROPE PART

void move_head(rope_part* head, int direction, int no_steps, node* set_ptr)
{
    if (head->prev_part != NULL)
    {
        printf("this is not head that is being moved\nexiting...\n");
        exit(0);
    }    
    
    for (int i = 0; i < no_steps; ++i)
    {
        if (direction == 0)
        {
            // up
            ++head->position[1];
            move_inner_rope_part(head->next_part, set_ptr);
        }
        else if (direction == 1)
        {
            // right
            ++head->position[0];
            move_inner_rope_part(head->next_part, set_ptr);
        }
        else if (direction == 2)
        {
            // down
            --head->position[1];
            move_inner_rope_part(head->next_part, set_ptr);
        }
        else if (direction == 3)
        {
            // left
            --head->position[0];
            move_inner_rope_part(head->next_part, set_ptr);
        }
    }
}




// THE ROPE LIST



// ALLOCATE HEAD OF THE ROPE IN MEMORY

rope_part* rope_init()
{
    rope_part* head = (rope_part*) malloc(sizeof(rope_part));
    if (head == NULL)
    {
        printf("lack of memory; head not allocated in memory\n");
        exit(0);
    } else
    {
        printf("memory for head allocated successfully\n");
    }
    
    head->prev_part = NULL;
    head->next_part = NULL;
    head->position[0] = 0;
    head->position[1] = 0;
    
    return head;
}


// ADD A ROPE PART; ALLOCATE AND LINK TO THE ROPE

void rope_push(rope_part* head)
{
    rope_part* current = head;
    while(current->next_part != NULL)
    {
        current = current->next_part;
    }
    
    // allocate new part at the end of the rope
    current->next_part = (rope_part*) malloc(sizeof(rope_part));
    
    if (current->next_part == NULL)
    {
        printf("lack of memory; rope part not allocated in memory\n");
        exit(0);
    } else
    {
        printf("memory for a rope part allocated successfully\n");
    }
    
        
    // initialize all members of the last rope_part
    current->next_part->prev_part = current;
    current->next_part->next_part = NULL;
    current->next_part->position[0] = 0;
    current->next_part->position[1] = 0;
}


void free_rope(rope_part* head)
{
    rope_part* current = head;
    while (current->next_part->next_part != NULL) current = current->next_part;
    
    while (current->prev_part != NULL)
    {
        free(current->next_part);
        current = current->prev_part;
        printf("freed a rope part from memory\n");
    }
    
    free(current);
    printf("freed the whole rope structure from memory\n");
     
}
