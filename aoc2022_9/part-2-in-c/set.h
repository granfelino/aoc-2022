#ifndef SET_H
#define SET_H

typedef struct node node;
node* set_alloc();
node* set_init(int* first_entry);
int set_check_dupl(node* head, int* arr);
void set_push(node* head, int* val_in);
void set_print(node* head);

#endif
