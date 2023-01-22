#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node
{
  int val[2];
  node* next;
};

node* set_init(int* first_entry)
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
    head->val[0] = first_entry[0];
    head->val[1] = first_entry[1];
    return head;
}

int set_check_dupl(node* head, int* arr)
{
    node* current = head;
    while (current->next != NULL)
    {
        if ((current->val[0] == arr[0]) && (current->val[1] == arr[1]))
        {
            printf("duplicate found");
            return 1;
        }    
        current = current->next;
    }
    
    if ((current->val[0] == arr[0]) && (current->val[1] == arr[1]))
        {
            printf("duplicate found\n");
            return 1;
        }    
        
    
    
    printf("\nno duplicates\n");
    return 0;
}

void set_push(node* head, int* val_in)
{
    if (set_check_dupl(head, val_in)) 
    {
        printf("position already saved\n");
        return;
    }
    
    node* current = head;
    while (current->next != NULL) current = current->next;
    
    current->next = (node*) malloc(sizeof(node));
    current->next->next = NULL;
    current->next->val[0] = val_in[0];
    current->next->val[1] = val_in[1];
    printf("node added successfully\n");
}

void set_print(node* head)
{
    printf("\nprinting values: \n");
    node* current = head;
    while(current->next != NULL)
    {   
        printf("(%d, %d) ; ", current->val[0], current->val[1]);    
        current = current->next;
    } 
    
    printf("(%d, %d) ; ", current->val[0], current->val[1]);    
}


/*
int main()
{   
    int ar1[2] = {0, 0};
    int ar2[2] = {1, 0};
    int ar3[2] = {0, 2};
    int ar4[2] = {3, 0};
    int ar5[2] = {3, 0};

    node* set = set_init(ar1);
    set_push(set, ar2);
    set_push(set, ar3);
    set_push(set, ar4);
    set_push(set, ar5);
    
    set_print(set);
    
    return 0;
}
*/
