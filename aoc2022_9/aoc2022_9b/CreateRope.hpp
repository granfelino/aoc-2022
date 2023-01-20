#ifndef CREATE_ROPE_HPP
#define CREATE_ROPE_HPP


#include <iostream>
#include <vector>
#include "Head.hpp"
#include "Tail.hpp"
#include "Rope.hpp"
using namespace std;

class CreateRope 
{
    public:
    CreateRope() 
    {
        create_rope();
    }
    // ~CreateRope() {};
    Head* get_head_ptr();
    Tail* get_tail_ptr();
    vector<Rope*>* get_body_ptr();
    void create_rope();


    Head* head;
    Tail* tail;
    vector<Rope*>* body_ptr;
};


Head* CreateRope::get_head_ptr() { return this->head; }

Tail* CreateRope::get_tail_ptr() { return this->tail; }

vector<Rope*>* CreateRope::get_body_ptr() { return this->body_ptr; }

void CreateRope::create_rope() 
{
    // allocating rope parts to memory
    this->head = new Head;
    this->tail = new Tail;
    
    this->body_ptr = new vector<Rope*>;
    for (int i = 0; i < 8; ++i)
    {
        this->body_ptr->push_back(new Rope);
    }
    

    // connecting head and tail to the body
    this->head->next_ptr = this->body_ptr->at(0);
    this->tail->prev_ptr = this->body_ptr->at(7);

    // connecting the body to itself and to head and tail
    for (int i = 0; i < 8; ++i)
    {
        // connecting the first body part to the head and to the next element
        if (i == 0)
        {   
            this->body_ptr->at(i)->next_ptr = this->body_ptr->at(i+1);
            this->body_ptr->at(i)->prev_ptr = this->head;
            continue;

        } else if (i == 7)
        {
            this->body_ptr->at(i)->prev_ptr = this->body_ptr->at(i-1);
            this->body_ptr->at(i)->next_ptr = this->tail;
            continue;

        }

        // case for other body parts
        // connect backwards
        this->body_ptr->at(i)->prev_ptr = this->body_ptr->at(i)->prev_ptr == nullptr ?
                                          this->body_ptr->at(i-1) : 
                                          this->body_ptr->at(i)->prev_ptr
        ;

        // connect forward
        this->body_ptr->at(i)->next_ptr = this->body_ptr->at(i)->next_ptr == nullptr ?
                                          this->body_ptr->at(i+1) : 
                                          this->body_ptr->at(i)->next_ptr
        ;
    }

}


#endif