#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct polynode *polypointer;

struct polynode
{
    int coef;
    int expon;
    polypointer link;
};
polypointer createnode()
{
    polypointer temp;
    temp=(polypointer)malloc(sizeof(struct polynode));
    return temp;
}


void readpolynomial(polypointer p)
{
    polypointer temp;
    int i, terms;
    printf("Enter the no. of terms\n");
    scanf("%d",&terms);
    for(i=0;i<terms;i++)
    {
        temp=createnode();
        printf("Enter the coefficient of term %d:", i+1);
        scanf("%d",&temp->coef);
        printf("Enter the  exponent  of  term %d:", i+1);
        scanf("%d",&temp->expon);
        insert_end(p,temp);
    }
}

void insert_end(polypointer p, polypointer temp)
{
    polypointer cur;
    cur=p;
    while(cur->link!=p)
        cur=cur->link;
        temp->link=p;
        cur->link=temp;
}

void display(polypointer p)
{
    polypointer cur;
    cur=p->link;
    char sign;

    while(cur!=p)
    {
        if(cur->coef>0)
            sign='+';
        else
            sign=' ';
        printf("%c%dx%d", sign, cur->coef, cur->expon);
        cur=cur->link;
    }
    printf("\n");
}

void evaluate(polypointer p)
{
    int x, res=0;
    polypointer temp;
    temp=p->link;

    printf("Enter the value of x\n");
    scanf("%d",&x);

    while(temp!=p)
    {
        res += temp->coef*pow(x,temp->expon);
        temp=temp->link;
    }

    printf("\nThe result of polynomial evaluation is %d\n", res);
}

polypointer padd(polypointer p1, polypointer p2)
{
    polypointer a, b, c, rear;
    int coefsum;
    c=createnode();
    c->link = c;
    rear=c;
    a=p1->link;
    b=p2->link;

    while(a!=p1 && b!=p2)
    {
        switch(compare(a,b))
        {
            case -1:    attach(b->coef, b->expon, &rear);
                        b=b->link;
                        break;
            case 0:     coefsum = a->coef + b->coef;
                        if(coefsum)
                            attach(coefsum, a->expon, &rear);
                        a=a->link;
                        b=b->link;
                        break;
            case 1:     attach(a->coef, a->expon, &rear);
                        a=a->link;
                        break;
        }
    }

    while(a!=p1)
    {
        attach(a->coef, a->expon, &rear);
        a=a->link;
    }
    while(b!=p2)
    {
        attach(b->coef, b->expon, &rear);
        b=b->link;
    }
    return c;
}

void attach(int coef, int expon, polypointer *rear)
{
    polypointer temp;
    temp = createnode();
    temp->coef=coef;
    temp->expon=expon;

    temp->link = (*rear)->link;
    (*rear)->link=temp;
    (*rear)=(*rear)->link;
}

int compare(polypointer a, polypointer b)
{
    if(a->expon<b->expon)
        return -1;
    else if(a->expon>b->expon)
        return 1;
    else
        return 0;
}


void main()
{
    int ch;
    polypointer p, p1, p2, psum;
    p=createnode();
    p1=createnode();
    p2=createnode();
    p->link=p;
    p1->link=p1;
    p2->link=p2;

    while(1)
    {
        p->link=p;
        p1->link=p1;
        p2->link=p2;

        printf("\n1.evaluate polynomial\n2.Add polynomial\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the polynomial in standard form\n");
                    readpolynomial(p);
                    printf("The entered polynomial is\n");
                    display(p);
                    evaluate(p);
                    break;

            case 2: printf("Enter the polynomial 1 in standard form\n");
                    readpolynomial(p1);
                    printf("Enter the polynomial 2 in standard form\n");
                    readpolynomial(p2);
                    printf("\n polynomial 1:");
                    display(p1);
                    printf("\n polynomial 2:");
                    display(p2);
                    psum=padd(p1,p2);
                    printf("\n the sum of the polynomial:");
                    display(psum);
                    break;
                default:exit(0);
                }
            }
        }
