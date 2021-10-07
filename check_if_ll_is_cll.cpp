#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

bool check(struct node* head_ref){
    struct node* curr=head_ref;
    if(head_ref==NULL){
        return false;
    }

    while(curr!=NULL and curr!=head_ref){
        curr=curr->next;
    }
    if(curr==head_ref){
        return true;
    }
    else{
        return false;
    }
}

void push(struct node** head_ref,int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=(*head_ref);
    *head_ref=newnode;
}

void print(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head=NULL;
    push(&head,5);
    push(&head,7);
    push(&head,9);
    push(&head,2);
    head->next->next->next->next=head;

    cout<<check(head);

}