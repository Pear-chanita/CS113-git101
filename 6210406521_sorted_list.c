// 6210406521 : Chanita Somraikhing
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};
void sort(struct node** head_ref, struct node* n){
  struct node* now;
  if(*head_ref==NULL || (*head_ref)->data >= n->data){
    n->next = *head_ref;
    *head_ref = n;
  }else{
    now = *head_ref;
    while(now->next!=NULL && now->next->data < n->data){
      now = now->next;
    }
    n->next = now->next;
    now->next = n;
  }
}
struct node *neww(int new_data){
  struct node* n = (struct node*) malloc(sizeof(struct node));
  n->data = new_data;
  n->next = NULL;
}
void print(struct node *head){
  struct node *temp = head;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp = temp->next;
  }
}
int main(){
  int input;
  struct node* head = NULL;
  while(1){
    scanf("%d",&input);
    if(input>-1){
      struct node *n = neww(input); 
      sort(&head,n);
    }
    else break;
  }print(head);
}