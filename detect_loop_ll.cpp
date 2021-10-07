#include <bits/stdc++.h>
using namespace std;
// It returns an iterator to the element if found, 
//else returns an iterator pointing to the end of unordered_set.
struct node
{
    int data;
    struct node* next;
};
struct node *head=NULL;

bool detectLoop(struct node *head){
    unordered_set<struct node*> s;
    struct node *curr=head;
    while(curr!=NULL){
        if(s.find(curr)!=s.end()){
            return true;
        }
        s.insert(curr);
        curr=curr->next;
    }
    return false;
}

void insertAtBegin(int value){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL){
        head=temp;
        temp->next=NULL;
        return;
    }
    temp->next=head;
    head=temp;
}

int main(){
    int n;
    cin>>n;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtBegin(x);
    }

   // head->next->next->next->next = head->next;

    bool ans=detectLoop(head);
    if(ans){
        printf("Loop found");
    }else{
        printf("Loop not found");
    }

    return 0;
}