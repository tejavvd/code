#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *prev=NULL;
node *head=NULL;
int insert(int x,int pos){
    node *temp=(node*)malloc(sizeof(node)),*curr=NULL;
    int count=1;
    temp->data=x;
    temp->next=NULL;
    if(pos==1){
        temp->next=head;
        head=temp;
        return 0;
    }
    curr=head;
    while(count!=pos-1){
        curr=curr->next;
        count++;
    }
    temp->next=curr->next;
    curr->next=temp;
    
}
void print(){
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}
int deleted(int pos){
    int count=1;
    node *prev=NULL,*curr=head;
    if(pos==1){
        prev=head;
        head=head->next;
        free(prev);
        return 0;
    }
    while(count!=pos){
        prev=curr;
        curr=curr->next;
        count++;
    }
    prev->next=curr->next;
    free(curr);
}
int reverseiterative(){
    node *prev=NULL,*after=NULL,*curr=head;
    while(curr!=NULL){
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    head=prev;
}
int printreverserecur(node *head){
    if(head->next!=NULL)
    printreverserecur(head->next);
    printf("%d ",head->data);
}
int printforwardrecur(node *head){
    if(head==NULL)
    return 0;
    printf("%d ",head->data);
    printforwardrecur(head->next);
}
int reverserecur(node *temp){
    node *curr=temp,*after=temp;
    if( after==NULL){
        head=prev;
        return 0;
    }
    else{
        after=after->next;
        curr->next=prev;
        prev=curr;
        reverserecur(after);
    }
}
int reverserecursimple(node *temp){
    if(temp->next==NULL)
    {
        head=temp;
        return 0;
    }
    reverserecursimple(temp->next);
    node *after=temp->next;
    after->next=temp;
    temp->next=NULL;
}
int main()
{
    insert(10,1);
    insert(20,1);
    insert(30,2);
    insert(40,4);
    insert(50,4);
    printf("%d\n",head);
    print();
    reverserecursimple(head);
    printf("%d\n",head);
    print();
}
