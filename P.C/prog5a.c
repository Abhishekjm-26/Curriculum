#include<stdio.h>
#define max 10
typedef struct
{
    int key;
}   element;


    int top=-1;
    element stack[max];
    char expr[20];

void push(int ele)
{
    stack[++top].key=ele;
}
char pop()
{
    return stack[top--].key;
}
int eval()
{
    char token;
    int op1,op2;
    int i=0;
    while(expr[i]!='\0')
    {
        token=expr[i++];
        if(isdigit(token))
        push(token-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(token)
            {
                case  '+':push(op1+op2);
                        break;
                case  '-':push(op1-op2);
                        break;
                case  '/':push(op1/op2);
                        break;
                case  '*':push(op1*op2);
                        break;
                case  '%':push(op1%op2);
                        break;
                case  '^':push(pow(op1,op2));
            }
        }
    }
    return pop();
}
void main()
{
    int res;
    printf("enter the postfix expression\n");
    gets(expr);
    res=eval();
    printf("the result is %d\n",res);
}









