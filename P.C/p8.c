#include<stdio.h>
#include<stdlib.h>

typedef struct listnode *listpointer;
struct listnode
{
    char ssn[10];
    char name[20];
    char dept[20];
    char desg[20];
    float salary;
    char phone[10];
    listpointer rlink,llink;
};

listpointer first=NULL;

listpointer createnode()
{
    listpointer temp;
    temp=(listpointer)malloc(sizeof(struct listnode));
    return temp;
}

void reademployee(listpointer temp)
{
    fflush(stdin);
    printf("SSN\t:");
    scanf("%s",temp->ssn);
    printf("NAME\t:");
    scanf("%s",temp->name);
    printf("DEPT\t:");
    scanf("%s",temp->dept);
    printf("DESG\t:");
    scanf("%s",temp->desg);
    printf("SALARY\t:");
    scanf("%f",&temp->salary);
    printf("PHONE\t:");
    scanf("%s",temp->phone);
}

void displayemployee(listpointer cur)
{
    printf("\nThe deleted student information\n");
    printf("SSN\t:%s\n",cur->ssn);
    printf("Name\t:%s\n",cur->name);
    printf("Department\t:%s\n",cur->dept);
    printf("Designation\t:%d\n",cur->desg);
    printf("Salary\t:%.2f\n",cur->salary);
    printf("Phone\t:%s\n",cur->phone);
}

void insert_front()
{
    listpointer temp;
    temp=createnode();
    reademployee(temp);
    temp->llink=temp->rlink=NULL;

    if(first==NULL)
    {
        first=temp;
        return;
    }

    temp->rlink=first;
    first->llink=temp;
    first=temp;
}

void delete_front()
{
    if(first->rlink==NULL)
    {
        displayemployee(first);
        free(first);
        first=NULL;
        return;
    }

    first=first->rlink;
    displayemployee(first->llink);
    free(first->llink);
}

void insert_end()
{
    listpointer temp, cur;
    temp=createnode();
    reademployee(temp);
    temp->llink=temp->rlink=NULL;

    if(first==NULL)
    {
        first=temp;
        return;
    }

    cur=first;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
}

void delete_end()
{
    listpointer cur;
    if(first->rlink==NULL)
    {
        displayemployee(first);
        free(first);
        first=NULL;
        return;
    }

    cur=first;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->llink->rlink=NULL;
    displayemployee(cur);
    free(cur);
}

void display()
{
    int count=0;
    listpointer temp;
    temp=first;
    printf("\nfirst <=> ");
    while(temp!=NULL)
    {
        printf("|%s|%s|%s|%s|%.2f|%s| <=> ",temp->ssn, temp->name, temp->dept, temp->desg, temp->salary, temp->phone);
        temp=temp->rlink;
        count++;
    }
    printf(" NULL\n");
    printf("\nNo. of employees : %d\n",count);
}

void main()
{
    int ele, ch, n, i;
    while(1)
    {
        display();
        printf("\n1.Create DLL\n2.Dequeue operations\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(first!=NULL)
                    {
                        printf("\nThe DLL is already created\n");
                        break;
                    }
                    printf("\nEnter the no. of employees\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        printf("\nEnter details of employee %d\n", i+1);
                        insert_end();
                    }
                    break;
            case 2: while(1)
                    {
                        display();
                        printf("1.Insert at Front\n2.Insert at End\n3.Delete at Front\n4.Delete at End\n5.Exit\n");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                            case 1: printf("\nEnter the employee details to insert at Front\n");
                                    insert_front();
                                    break;

                            case 2: printf("\nEnter the employee details to insert at End\n");
                                    insert_end();
                                    break;

                            case 3: if(first==NULL)
                                    printf("\nDLL is empty\n");
                                    else
                                    delete_front();
                                    break;

                            case 4: if(first==NULL)
                                    printf("\nDLL is empty\n");
                                    else
                                    delete_end();
                                    break;

                            default: exit(0);
                        }
                    }
        }
    }
}
