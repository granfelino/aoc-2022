#ifndef TAIL_HPP
#define TAIL_HPP    


/*
Class Tail, child class of Rope
*/

#include <iostream>
#include <array>
#include <set>
#include <assert.h>
#include "Rope.hpp"

using namespace std;


class Tail : public Rope
{
    public:
    Tail() : Rope() 
    {
        // add {0, 0} to places at the start
        this->add_place(this->position);
    }
    ~Tail() {};
    void    add_place(array<int, 2> place);
    void    set_places_count();
    int     get_places_count();
    void    move();
    
    
    set<array<int, 2>> tail_places;
    int     tail_places_count;
};


void Tail::add_place(array<int, 2> place)
{
    this->tail_places.insert(place);
}


void Tail::set_places_count()
{
    this->tail_places_count = this->tail_places.size();
}


int Tail::get_places_count() {
    set_places_count();
    return this->tail_places_count;
}


// overridden move function of the Rope parent class
// same as Rope class, just calls append_place function at the end
void Tail::move()
{
    array<int, 2> offset = Tail::get_offset();

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

    Tail::add_place(this->position);
}


#endif