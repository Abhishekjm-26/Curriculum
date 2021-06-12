#include<stdio.h>
void tower(int n,char src,char dest,char aux)
{
  if(n==1)
  {
    printf("disk 1 move from %c to %c\n",src,dest);
    return;

  }
  tower( n-1,src,aux,dest);
  printf(" disk %d move from %c to %c\n",n,src,dest);
  tower(n-1, aux,dest,src);
}
void main()
{
  int n;
  printf("enter the no of disk\n");
  scanf("%d",&n);
  tower(n,'A','C','B');
  printf("The no of disk moves =%d\n",(int)pow(2,n)-1);
}
