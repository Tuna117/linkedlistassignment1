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

void findn(Node *curr, int n) {

    int i=1;
    while(curr) {

        if(i==n+1) {
        printf("The searched element of the linked list is the number %d\n", i, curr->number);
        break;
        }
        curr=curr->next;
        i++;
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

    printf("Enter the nth node to be searched from the end of the linked list:\n");
    int n;
    scanf("%d", &n);

    n=N-n;
    findn(head, n);
    return 0;
}