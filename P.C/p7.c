#include<stdio.h>
#include<stdlib.h>

typedef struct listnode *listpointer;
struct listnode
{
    char USN[11];
    char NAME[20];
    char PRG[3];
    int sem;
    long long int phone;
    listpointer link;
 };
    listpointer first=NULL;

    listpointer createnode()
 {
    listpointer temp;
    temp=(listpointer)malloc(sizeof(struct listnode));
    return temp;
 }
    void readstudent(listpointer temp)
 {
    printf("USN\n");
    scanf("%s",temp->USN);
    printf("name\n");
    scanf("%s",temp->NAME);
    printf("program\n");
    scanf("%s",temp->PRG);
    printf("sem\n");
    scanf("%d",&temp->sem);
    printf("phone number\n");
    scanf("%lld",&temp->phone);
 }
    void displaystudent(listpointer cur)
 {
    printf("the student details are\n");
    printf("USN: %s\t",cur->USN);
    printf("NAME: %s\n",cur->NAME);
    printf("program: %s\t",cur->PRG);
    printf("sem: %d\n",cur->sem);
    printf("phone number: %lld\n",cur->phone);
 }
    void insert_front()
 {
    listpointer temp;
    temp=createnode();
    readstudent(temp);
    temp->link=first;
    first=temp;
 }
    void delete_front()
 {
    listpointer cur;
    cur=first;
    displaystudent(cur);
    first=first->link;
    free(cur);
 }
   void insert_end()
{
    listpointer temp,cur;
    temp=createnode();
    readstudent(temp);
    temp->link=NULL;
    if(first==NULL)
    {
        first=temp;
        return;
    }
    cur=first;
    while(cur->link!=NULL)
      cur=cur->link;
    cur->link=temp;

}

void delete_end()
{
    listpointer cur,prev;
    if(first->link==NULL)
    {
        displaystudent(first);
        free(first);
        first=NULL;
        return;
    }
    cur=first;
    prev=NULL;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=NULL;
    displaystudent(cur);
    free(cur);
}
void display()

{
    int count=0;
    listpointer temp;
    printf("student details are\n");
    temp=first;
    while(temp!=NULL)
    {
        printf("|%s| |%s| |%s| |%d| |%lld| --->",temp->USN,temp->NAME,temp->PRG,temp->sem,temp->phone);
        temp=temp->link;
        count++;
     }
     printf("NULL\n");
     printf("\nNo. of students : %d\n",count);
}


void main()

{

    int ch,n,i,ch1;
    while(1)
{
        display();
        printf("enter\n1.create node\n2.insert end\n3.delete end\n4.stack operation\n5.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(first!=NULL)
                    {
                        printf("node is already created\n");
                        break;
                    }
                    else
                    {
                        printf("enter number of nodes\n");
                        scanf("%d",&n);
                        for(i=0;i<n;i++)
                        {
                            printf("the student %d details are\n",i+1);
                            insert_front();

                        }
                    }
                    break;
            case 2: printf("\nenter the student details to insert at end\n");
                    insert_end();
                    break;
            case 3: if(first==NULL)
                    printf("\n list is emp[ty\n");
                    else
                    delete_end();
                    break;
            case 4: while(1)
                    {
                        display();
                        printf("stack operation\n1.push\n2.pop\n3.exit\n");
                        scanf("%d",&ch1);
                        if(ch1==3)
                            break;
                        switch(ch1)
                        {
                            case 1: printf("\nenter the student details to push(insert at front)\n");
                                    insert_front();
                                     break;
                            case 2: if(first==NULL)

                                        printf("\nlist is empty\n");
                                        else
                                            delete_front();
                                            break;
                                    }
                        }
                        break;
            default: exit(0);
                   }
        }
    }









