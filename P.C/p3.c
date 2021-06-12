#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

typedef struct
{
    int key;
}element;
element stack[MAX];
int top=-1;

int isempty()
{
    return top==-1?1:0;
}

int isfull()
{
    return top==MAX-1?1:0;
}

void push(int ele)
{
    stack[++top].key=ele;
}

int pop()
{
    return stack[top--].key;
}

int display()
{
 int i;
 if(isempty())
    printf("STACK IS EMPTY \n");
 else
{
    printf("          \n");
    printf("THE STACK ELEMENTS ARE  \n");
    for(i=top;i>=0;i--)
    printf("stack[%d] %d\n",i,stack[i].key);
    printf("          \n");
}
 if (isfull())
    printf("STACK IS FULL \n");
}

void checkpalindrome()
{
    char n1[10],n2[10];
    printf("ENTER THE NUMBER :");
    scanf("%s",n1);
  if(strlen(n1)>MAX-top-1)
    printf("THERE IS NOT ENOUGH SPACE ON THE STACK \n");
  else
   {
    int i;
    for(i=0;n1[i]!='\0';i++)
    push(n1[i]-0);
    for(i=0;i<strlen(n1);i++)
    n2[i]=pop()+0;
    n2[i]='\0';
    if(strcmp(n1,n2))
     printf("THE NUMBER IS NOT A PALINDROME\n");
  else
     printf("THE NUMBER IS  PALINDROME\n");
   }
}

void main()
{
int ele,ch,i;
while(1)
{

      display();
      printf("\n STACK OPERATION\n");
      printf("\n 1.PUSH\n 2.POP\n 3.CHECK PALINDROME\n 4.EXIT\n");
      scanf("%d",&ch);

      switch(ch)
       {
           case 1: if(isfull())
                        printf("STACK IS OVERFLOWING\n");
                   else
                     {
                        printf("enter the element\n");
                        scanf("%d",&ele);
                        push(ele);
                     }
                     break;

           case 2: if(isempty())
                        printf("STACK IS UNDERFLOWING\n");
                    else
                      {
                        ele=pop();
                      }
                        break;

           case 3: checkpalindrome();
                   break;
          default: exit(0);

        }
}
}
