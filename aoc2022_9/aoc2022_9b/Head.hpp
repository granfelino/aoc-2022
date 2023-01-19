#ifndef HEAD_HPP
#define HEAD_HPP


/*
Class Head, child class of Rope
*/

#include <iostream>
#include <vector>
#include <array>
#include "Rope.hpp"

using namespace std;

class Head : public Rope
{
    public:
    Head() : Rope() {}
    ~Head() {};
    void move(array<int, 2> move);
    
    array<int, 2> position;

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


#endif