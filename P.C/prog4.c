#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
typedef struct
{
  int key;
} element;

 int top=-1;
 element stack[max];
 char infix[20],postfix[20];
 void push(char elem)
{
  stack[++top].key=elem;
}
  char pop()
{
  return stack[top--].key;
}
  int isempty()
{
  return top==-1?1:0;
}
  int precedence(char symbol)
{
    switch(symbol)
  {
     case '(':return 0;
     case '+':return 1;
     case '-':return 1;
     case '*':return 2;
     case '/':return 2;
     case '%':return 2;
     case '^':return 3;
  }
}

   void topostfix()
{
   int i=0,j=0;
   char token;
   while(infix[i]!='\0')
   {
     token=infix[i++];
     if(isdigit(token)||isalpha(token))
     postfix[j++]=token;
     else if (token=='(')
     push(token);
     else if (token==')')
     {
         while(stack[top].key!='(')
         postfix[j++]=pop();
         pop();
       }

       else
     {

       while(precedence(stack[top].key)>=precedence(token)&&!isempty())
         postfix[j++]=pop();
         push(token);
       }
     }
      while(!isempty())
      postfix[j++]=pop();


   }

     void main()
 {
     printf("enter the infix\n");
     gets(infix);
     topostfix();
     printf("the postfix is %s\n",postfix);
 }

