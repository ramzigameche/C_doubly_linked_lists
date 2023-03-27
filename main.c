#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    struct node* prev;
    int value;
    struct node* next;
}node;
//-------(the function the check if the linked list is free)-----------------------
int verif(struct node** head){
    int i;
if (head==NULL){
   i=1;
}
else {
    i=0;
}
return i;
}
//---------------------------------------------------------------------------------
//-----the function that add a new element to a free linked list-------------------
struct node* add_to_empty(struct node* head, int value){
   struct node* temp=malloc(sizeof(struct node));
   temp->prev=NULL;
   temp->value=value;
   temp->next=NULL;
   head=temp;
   return head;
};
//---------------------------------------------------------------------------------
//------the function that add a new element at the Beginning of a linked list------
struct node* add_at_beg(struct node* head, int value){
    struct node* p=malloc(sizeof(struct node));
    p->prev=NULL;
    p->value=value;
    p->next=NULL;
    p->next=head;
    head->prev=p;
    head = p;
    return head;
};
//---------------------------------------------------------------------------------
//----the function that add a new element at the end of a linked list--------------
struct node* add_at_end(struct node* head, int value){
    struct node* p=malloc(sizeof(struct node));
    struct node* q;
    p->prev=NULL;
    p->next=NULL;
    p->value=value;
    q=head;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
    p->prev=q;
    return head;
};
//---------------------------------------------------------------------------------
//--the function that read the values of the element of the linked lists-----------
void read_ll(struct node* head){
   struct node* q;
   q = head ;
   while (q != NULL){
    printf("%d\n",q->value);
    q=q->next;
   }
}
//------------creat doubly linked list --------------------------------------------
void create(struct node **head){
int n;
printf("Enter the number of nodes: ");
scanf("%d",&n);
for (int i = 0; i < n; ++i) {
int x;
printf("Enter the value of node %d: ",i);
scanf("%d",&x);
add_at_end(head,x);
}
}
//----------------delete_NOde-----------------------------------------------------
void delet_n (struct Node** head, int k) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    struct node* curr_node = *head;
    int count = 1;

    while ( curr_node && count != k) {
        curr_node = curr_node->next;
        count++;
    }

    if (curr_node == NULL) {
        printf("Error: Index out of range\n");
        return;
    }

    struct node* prev_node = curr_node->prev;
    struct node* next_node = curr_node->next;

    if (prev_node) {
        prev_node->next = next_node;
    } else {
        *head = next_node;
    }

    if (next_node) {
        next_node->prev = prev_node;
    }

    free(curr_node);
}
//---------------delete_list-------------------------------------------------------
void clear_list(struct node **head){
struct node *q;
q = *head;
while(q != NULL) {
struct node *tmp;
tmp = q;
q = q->next;
free(tmp);
}
*head = NULL;
}
//---------------------------------------------------------------------------------
//--------------search-value-------------------------------------------------------
void sea_val(struct node *head,int n){
struct node *q;
q = head;
int k = 0;
int found = 0;
while(q != NULL) {
if(q->value == n){
found = 1;
printf("The number %d is in the list and it is at position %d \n",n,k);
break;
}
q = q->next;
k++;
}
if(found == 0){
printf("It doesn't exist.\n");
}
}
//---------------------------------------------------------------------------------
//---------list's length-----------------------------------------------------------
void get_list_length(struct node *head){
struct node *q;
q = head;
int length = 0;
while(q != NULL) {
q = q->next;
length++;
}
printf("The length of the list is %d.\n",length);
}
//---------------------------------------------------------------------------------
//--------------------------insert_at_a_given_position_which_is_a_position_k-------
void insertAtK(struct Node** head, int data, int k) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL && k == 0) {
        *head = new_node;
        return;
    }

    struct node* curr_node = *head;
    struct node* prev_node = NULL;
    int i = 0;

    while (curr_node != NULL && i < k) {
        prev_node = curr_node;
        curr_node = curr_node->next;
        i++;
    }

    if (i < k) {
        printf("Position %d does not exist in the list\n", k);
        return;
    }

    if (prev_node == NULL) {
        *head = new_node;
    } else {
        prev_node->next = new_node;
        new_node->prev = prev_node;
    }

    new_node->next = curr_node;

    if (curr_node != NULL) {
        curr_node->prev = new_node;
    }
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
int main()
{
    struct node* head=NULL;
    create(head);
    head = add_to_empty(head,15);
    head = add_at_beg(head,14);
    head = add_at_end(head,30);
    read_ll(head);

    return 0;
}
