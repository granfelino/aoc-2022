/*
Class Head, child class of Rope
*/

#include <iostream>
#include <array>
#include <Rope.cpp>

using namespace std;

class Head : Rope
{
public:
    Rope *next_ptr, *prev_ptr;
    array<int, 2> position;

    
    Head()
    {
        this->position = {0, 0};
        this->prev_ptr = nullptr;
        this->next_ptr = nullptr;
    }

    void move(array<int, 2> move);

    };


void Head::move(array<int, 2> move)
{
    for (int i = 0; i < move[1]; ++i)
    {
        if (move[0] == 0)
        {
            // up
            ++this->position[1];
            this->next_ptr->move();
        }
        else if (move[0] == 1)
        {
            // right
            ++this->position[0];
            this->next_ptr->move();
        }
        else if (move[0] == 2)
        {
            // down
            --this->position[1];
            this->next_ptr->move();
        }
        else if (move[0] == 3)
        {
            // left
            --this->position[0];
            this->next_ptr->move();
        }
    }
}

