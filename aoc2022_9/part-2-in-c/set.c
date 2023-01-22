#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node
{
  int val[2];
  node* next;
};

node* set_init()
{
    node* head = (node*) malloc(sizeof(node));
    if (head == NULL) 
    {
        printf("lack of memory; did not create a set node\n");
        exit(0);
    } else
    {
        printf("head created successfully\n");
    }
    
    head->next = NULL;    
    return head;
}

int main()
{   
    
    return 0;
}
