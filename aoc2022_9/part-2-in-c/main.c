#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rope.h"

int main()
{
    rope_part* head = rope_init();
    for (int i = 0; i < 9; ++i)
    {
        rope_push(head);
    }
    
    move_head(head, 2, 20);
    move_head(head, 1, 2);
    
 	free_rope(head);   
     
	return 0;
}
