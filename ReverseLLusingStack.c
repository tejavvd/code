#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head=NULL;
int top=-1;
int insert(int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=head;
    head=temp;
}
int push(node **stack,node *curr){
    stack[++top]=curr;
}
node* pop(node **stack){
    return stack[top--];
}
int print(){
    node *curr=head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

int main(){
    node **stack=(node**)malloc(sizeof(node*)*5);
    /* Creating stack as pointer to pointer coz Each element is a pointer to LL node. So sizeof(node*) is taken.
    
    */
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    node *curr=head;
    for(int i=0;i<5;i++){
        push(stack,curr);
        curr=curr->next;
    }
    node *temp=pop(stack);
    temp->next=stack[top];
    node *temp2=stack[top];
    while(temp2!=head){
        pop(stack);
        temp2->next=stack[top];
        temp2=stack[top];
    }
    temp2->next=NULL;
    head=temp;
    print();
}
