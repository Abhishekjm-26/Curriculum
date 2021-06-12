#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int *createarray(int*a,int n)
{
    int i;
    a=(int*)malloc(MAX*sizeof(int));
    printf("enter the array elements \n");
    for(i=0;i<n;i++)
    scanf("%d",a+i);
    return a;

}
void displayarray(int*a,int n)
{
    int i;
    printf("the array elements are \n");
        for(i=0;i<n;i++)
        printf("%d\t",*(a+i));
        printf("the number of elments %d \n",n);

}
 int insertarray(int*a,int n)
 {
    int elem,pos,i;
    printf("enter the array position to insert \n");
    scanf("%d",&pos);
    if(pos>=0&&pos<=n)
    {
        printf("insert the array element \n");
        scanf("%d",&elem);
        for(i=n;i>pos;i--)
            *(a+i)=*(a+i-1);
        *(a+pos)=elem;
        n+=1;

    }
    else
        printf("invalid position cannot insert \n");
        return n;
}
int deletearray(int*a,int n)
{
    int pos,i;
    printf("enter the array position to delete \n");
    scanf("%d",&pos);
    if(pos>=0&&pos<n)
    {
        printf("the deleted element is %d\n",*(a+pos));

        for(i=pos;i<n-1;i++)
            *(a+i)=*(a+i+1);
            n-=1;
    }
     else
          printf("invalid position cannot delete \n");
          return n;
}
void main()
{

    int ch,*a,n;
    while(1)
    {
        printf("enter the choice::\n1.create\n 2.display\n 3.insert\n 4.delete\n 5.exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("enter rhe size of the array ");
                    scanf("%d",&n);
                    a=createarray(a,n);
                    break;
            case 2:displayarray(a,n);

                    break;

            case 3:if(n==MAX)
                   printf("elements cannot be inserted ");
                   else
                   n=insertarray(a,n);
                    break;
            case 4:if(n==0)
                   printf("elements cannot be deleted");
                   else
                   n=deletearray(a,n);
                   break;
            case 5:exit(0);



        }

    }

}
















