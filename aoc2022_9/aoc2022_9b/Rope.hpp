/*
Rope class
*/

#include <iostream>
#include <array>
#include <assert.h>

using namespace std;

class Rope
{
public:
    Rope *next_ptr, *prev_ptr;
    array<int, 2> position;

    Rope()
    {
        this->position = {0, 0};
        this->prev_ptr = nullptr;
        this->next_ptr = nullptr;
    }

    void virtual move();
    array<int, 2> get_offset();
};

void Rope::move()
{
    array<int, 2> offset = Rope::get_offset();

    if (abs(offset[0]) <= 1 && abs(offset[1]) <= 1)
    {
        // no movement
        return;
    }
    else if (offset[0] == 0 xor offset[1] == 0)
    {
        // horizontal/vertical movement

        if (offset[0] == 0)
        {
            // vertical

            if (offset[1] > 0)
                ++this->position[1]; // up
            else
                --this->position[0]; // down
        }
        else
        {
            // horizontal

            if (offset[0] > 0)
                ++this->position[0]; // right
            else
                --this->position[0]; // left
        }
    }
    else
    {
        // assert that offset is between (-2 and -1) and (1, 2) on both axes

        assert(abs(offset[0] >= 1));
        assert(abs(offset[0] <= 2));

        assert(abs(offset[1] >= 1));
        assert(abs(offset[1] <= 2));

        // left upper
        if (offset[0] < 0 && offset[1] > 0)
        {
            --this->position[0];
            ++this->position[1];
        }

        // right upper
        else if (offset[0] > 0 && offset[1] > 0)
        {
            ++this->position[0];
            ++this->position[1];
        }

        // right lower
        else if (offset[0] > 0 && offset[1] < 0)
        {
            ++this->position[0];
            --this->position[1];
        }

        // left lower
        else if (offset[0] < 0 && offset[1] < 0)
        {
            --this->position[0];
            --this->position[1];
        }
    }

    // call the move method on the next rope piece if it is not the tail of the rope
    if (this->next_ptr != nullptr)
        this->next_ptr->move();
}

array<int, 2> Rope::get_offset()
{
    array<int, 2> offset = {};
    offset[0] = this->prev_ptr->position[0] - this->position[0];
    offset[1] = this->prev_ptr->position[1] - this->position[1];
    assert(abs(offset[0]) <= 2);
    assert(abs(offset[1]) <= 2);

    return offset;
}