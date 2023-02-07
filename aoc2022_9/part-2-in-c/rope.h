#ifndef ROPE_H
#define ROPE_H
#include "set.h"

typedef struct rope_part rope_part;
void get_offset(int* buf, rope_part* part, rope_part* prev);
void move_inner_rope_part(rope_part* part, node* set_ptr);
void move_head(rope_part* head, int direction, int no_steps, node* set_ptr);
rope_part* rope_init();
void rope_push(rope_part* head);
void free_rope(rope_part* head);




#endif
