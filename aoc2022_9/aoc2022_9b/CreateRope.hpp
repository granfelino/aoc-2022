#include <iostream>
#include <vector>
#include <Head.hpp>
#include <Tail.hpp>
#include <Rope.hpp>
using namespace std;

class CreateRope 
{
    public:
    Head* head;
    Tail* tail;
    vector<Rope*>* body_ptr;

    CreateRope() 
    {
        create_rope();
    }

    void create_rope();
};


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
    

    // connecting the rope pieces together
    this->head->set_next_ptr(this->body_ptr->at(0));
}

