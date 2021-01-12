#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int number;
    Node *next;
};

Node *head1;
Node *head2;
Node *tail1;
Node *tail2;

Node *createNodeL1(int number)
{
    Node *newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->number=number;
    newNode1->next=NULL;
    return newNode1;
}

Node *createNodeL2(int number)
{
    Node *newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->number=number;
    newNode2->next=NULL;
    return newNode2;
}

void pushTailL1(int number) {
    Node *temp=createNodeL1(number);
 
    if(!head1){
        head1=tail1=temp; 
    }
    else {
        tail1->next=temp;
        tail1=temp;
    }
}

void pushTailL2(int number) {
    Node *temp=createNodeL2(number);
 
    if(!head2){
        head2=tail2=temp; 
    }
    else {
        tail2->next=temp;
        tail2=temp;
    }
}

void pushHeadL1(int number) {

    Node *temp=createNodeL1(number);

    if(!head1) { 
        head1=tail1=temp;
    }

    else {
        temp->next=head1;
        head1=temp;
    }
}

void pushHeadL2(int number) {

    Node *temp=createNodeL2(number);

    if(!head2) { 
        head2=tail2=temp;
    }

    else {
        temp->next=head2;
        head2=temp;
    }
}

void printList(Node *curr) {
    while(curr) {
        printf("%d ", curr->number);
        curr=curr->next;
    }
}

Node *merge(Node *head1, Node *head2) {
    
    if(!head1->next) {
        head1->next=head2;
        return head1;
    }

    Node *curr1=head1, *next1=head1->next, *curr2=head2, *next2=head2->next;

    while(next1 && curr2)
    {
        if(curr2->number >= curr1->number && curr2->number <= next1->number) {
            next2=curr2->next;
            curr1->next=curr2;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }

        else {
            if(next1->next) {
                next1=next1->next;
                curr1=curr1->next;
            }

            else {
                next1->next=curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node *NewNode(Node *head1, Node *head2) {

    if(head1->number < head2->number)
    merge(head1, head2);

    else if(head2->number < head1->number)
    merge(head2, head1);
}

int main()
{
    printf("Enter size M for L1 and N for L2:\n");
    int N, M;
    printf("M:");
    scanf("%d", &M);

    printf("N:");
    scanf("%d", &N);

    printf("Enter numbers for L1:\n");
    int x;
    for(int i=0; i<M; i++)
    {
        if(i==0){
        scanf("%d", &x);
        pushHeadL1(x);
        }
        else {
        scanf("%d", &x);
        pushTailL1(x);
        }
        x=0;
    }

    printf("Enter numbers for L2:\n");
    int y;
    for(int i=0; i<N; i++)
    {
        if(i==0){
        scanf("%d", &y);
        pushHeadL2(y);
        }
        else {
        scanf("%d", &y);
        pushTailL2(y);
        }
        y=0;
    }

    Node *result=NewNode(head1, head2);
    printList(result);
    return 0;
}