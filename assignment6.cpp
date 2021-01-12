#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int number;
    Node *next;
};

Node *head;
Node *tail;

Node *createNode(int number)
{
    Node *newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->number=number;
    newNode1->next=NULL;
    return newNode1;
}

void pushTail(int number) {
    Node *temp=createNode(number);
    if(!head){
        head=tail=temp; 
    }
    else {
        tail->next=temp;
        tail=temp;
    }
}

void pushHead(int number) {
    Node *temp=createNode(number);
    if(!head) { 
        head=tail=temp;
    }

    else {
        temp->next=head;
        head=temp;
    }
}

void sortDescending() {
    
    Node *prev, *curr;
    if(head) {
        prev=head;
        curr=head->next;
        head=head->next;
        prev->next=NULL;
    }

    while(head) {
        head=head->next;
        curr->next=prev;
        prev=curr;
        curr=head;
    }
    head=prev;
}

void printList(Node *curr) {
    while(curr) {
        printf("%d ", curr->number);
        curr=curr->next;
    }
}

int main()
{
    printf("Enter size of the list:\n");
    int N;
    printf("N:");
    scanf("%d", &N);

    printf("Enter numbers for the list:\n");
    int x;
    for(int i=0; i<N; i++)
    {
        if(i==0){
        scanf("%d", &x);
        pushHead(x);
        }
        else {
        scanf("%d", &x);
        pushTail(x);
        }
        x=0;
    }

    sortDescending();
    printList(head);

    return 0;
}