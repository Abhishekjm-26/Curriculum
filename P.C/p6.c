#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    char key;
}element;

element cqueue[MAX];
int front=0;
int rear=0;


int isempty()
{
    return front==rear?1:0;
}

int isfull()
{
    return (rear+1)%MAX==front?1:0;
}

void cqinsert(char ele)
{
    rear=(rear+1)%MAX;
    cqueue[rear].key=ele;
}

int cqdelete()
{
    front=(front+1)%MAX;
    return cqueue[front].key;
}

void display()
{
    int i;
    if(isempty())
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements are\n");
        printf("............\n");

        for(i=(front+1)%MAX;i!=(rear+1)%MAX;i=(i+1)%MAX)
            printf("\ncqueue[%d]= %c\n",i,cqueue[i].key);
        printf("..............\n");
    }
    if(isfull())
        printf("\nQueue is full\n");
        printf("\nfront = %d\n",front);
        printf("\nrear  = %d\n",rear);
}

void main()
{
    int ch;
    char ele;
    display();
    while(1)
    {
        printf("\nCircular Queue Operations\n");
        printf("1.Insert\n2.Delete\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if (isfull())
                        printf("Circular Queue Overflow\n");
                    else
                    {
                        printf("enter the element to insert\n");
                        scanf("%c",&ele);
                        scanf("%c",&ele);
                        cqinsert(ele);
                        display();
                    }
                    break;
            case 2: if (isempty())
                        printf("Circular Queue is Underflow\n");
                    else
                    {
                        ele=cqdelete();
                        printf("The Deleted Element is %c\n",ele);
                        display();
                    }
                    break;
            default: exit(0);
        }
    }
}
