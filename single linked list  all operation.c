//single linked list  all operation
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node *root=NULL;
void addl()//1
{
struct node *temp;
struct node *p;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the node element=");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
root=temp;
else
{
p=root;
while(p->link!=NULL)
p=p->link;
}
p->link=temp;
}
void addf()//2
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the node element");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
root=temp;
else
{
temp->link=root;
root=temp;
}
}
int length()//3
{
int c=0;
struct node *p;
p=root;
while(p!=NULL)
{
c++;
p=p->link;
}
return c;
}
void print()//4
{
struct node *p;
p=root;
if(p==NULL)
printf("the linkedlist is empty\n");
else
{
while(p!=NULL)
{
printf("%d  ",p->data);
p=p->link;
}
}
}
void delete()//5
{
struct node *temp=root;
struct node *p=root;
int x;
printf("enter the postion where the node element should delete \n");
scanf("%d",&x);
if(x>length())
{
printf("invalid postion\n");
}
else if(x==1)
{
temp=root->link;
root=temp;
temp->link=NULL;
free(temp);
}
else
{
struct node *q;
int i=1;
while(i<(x-1))
{
p=p->link;
i++;
}
q=p->link;
p->link=q->link;
q->link=NULL;
free(q);
}
}
void addformpos()//6
{
struct node *temp;
struct node *p=root;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the node element");
scanf("%d",&temp->data);
int x;
printf("enter the postion where the node element should add\n");
scanf("%d",&x);
int i=1;
while(i<(x-1))
{
p=p->link;
i++;
}
struct node *q=p->link;
temp->link=q;
p->link=temp;
}
void swap()//7
{
struct node *q,*r;
struct node *p=root;
int x,i=0;
printf("enter the postion where the node will shift with the next node\n");
scanf("%d",&x);
x=x-1;
if(x==length())
printf("there is no next node fr swaping");
else
{
while(i<(x-1))
{
p=p->link;
i++;
}
r=p->link;
q=r->link;
r->link=q->link;
p->link=q;
q->link=r;
}}

void reverse()//8
{ int t;
struct node *q=root;
struct node *p=root;
int i=0,j,k;
j=length()-1;
while(i<j)
{ k=0;
while(k<j)
{
q=q->link;
k++; 
}
t=p->data;
p->data=q->data;
q->data=t;
i++;
j--;
p=p->link;
q=root;
}
}
struct node *revpr(struct node *p)//9
{

if(p==NULL)
return NULL;
else
{

revpr(p->link);
printf("%d  ",p->data);
}
}
int main() 
{
int ch,e,x,l;
while(1)
{
printf("\n");
printf("\n");
printf("\n");
printf("enter 1 for add for first\n");
printf("enter 2 for add for last\n");
printf("enter 3 for add for any postion\n");
printf("enter 4 for length\n");
printf("enter 5 for print\n");
printf("enter 7 for swap\n");
printf("enter 8 for reverse\n");
printf("enter 6 for delete\n");
printf("enter 9 for print reverse\n");
printf("enter 0 for quit\n");
printf("enter the choice = ");
scanf("%d",&ch);
switch(ch) {
case 1: addf(); break;   case 2: addl(); break;   case 3: addformpos(); break;
case 4: l=length(); printf("the length of linked list is  %d\n",l); break;
case 5: print(); break;   case 6: delete(); break;   case 7: swap(); break;
case 8: reverse(); break;
case 9: revpr(root); break;


   case 0: exit(0); break; default: printf("invalid\n");
} } }









