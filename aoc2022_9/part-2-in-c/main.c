#include <stdio.h>

typedef struct rope_part rope_part;

struct rope_part
{
	rope_part* prev_part;
	rope_part* next_part;
	int position[2];
};


void get_offset(int* buf, rope_part* part, rope_part* prev)
{
	int x = prev->position[0] - part->position[0];
	int y = prev->position[1] - part->position[1];
	buf[0] = x;
	buf[1] = y;
}


void move_rope_part(rope_part* part, int direction, int no_steps)
{
	int offset[2];
	get_offset(offset, part, part->prev_part);

}

int main()
{
	return 0;
}
