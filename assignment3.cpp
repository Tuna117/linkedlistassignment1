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
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->number=number;
    newNode->next=NULL;
    return newNode;
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

void findMiddle(Node *curr, int mid) {

    int i=1;
    while(curr) {

        if(i==mid) {
        printf("The middle element of the linked list is the number %d\n", curr->number);
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

    int middle;
    if(N%2!=0)
    middle=N/2+1;
    
    else if(N%2==0)
    middle=N/2;

    findMiddle(head, middle);

    return 0;
}