#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
};
typedef struct node N;

N *start=NULL;
void create(char a[],int n)
{
    N *ptr,*temp;
       temp=(N *)malloc(sizeof(N));
           temp->data=a[0];
       temp->next=NULL;
    start=temp;
    ptr=start;
    for(int i=1;i<n;i++)
    { temp=(N *)malloc(sizeof(N));
      temp->data=a[i];
    temp->next=NULL;
    ptr->next=temp;
    ptr=ptr->next;
    }
    }

void rev()
{

    N *pre,*cur;
    pre=start;
    cur=start->next;
    start=start->next;
    pre->next=NULL;
    while(start!=NULL)
    {
        start=start->next;
        cur->next=pre;
        pre=cur;
        cur=start;

    }
    start=pre;
}
void disp()
{
     N *ptr;
        ptr=start;
        printf("The reversed string is :");
        while(ptr!=NULL)
        {
            printf("\t%c",ptr->data);
            ptr=ptr->next;
        }

}
main()
{
    char a[100];
    printf("Enter the string you want to reverse \n");
    scanf("%s",&a);
    int n=strlen(a);
    create(a,n);
    rev();
    disp();

}
