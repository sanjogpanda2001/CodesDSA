#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class node
{
    public:
    int data;
    node* link;

};
int c=0;
node* first=NULL;
void display(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->link;
    }
}
node* n=NULL; // if it is declared inside , den the code dosent works
void insertion(int v1)
{
    int d=0;
    
   node* temp=new node;
   temp->data=v1;
   temp->link=NULL;
   if(first==NULL)
  {
       first=n=temp;
  }
   else
   {
       n->link=temp;
       n=temp;
   }
   
}

void swap(int x,int y)
{
    node *p=first;
    node *q=first;
    node* temp=NULL;
    node* follow2,*follow1;
   
    p=first;q=first;
    for(int i=1;i<x;i++)
   { 
       follow1=p;
       p=p->link;
    }

    for(int i=1;i<y;i++)
    {
        follow2=q;
        q=q->link;
    }
    if(x==1)
    {
        follow2->link=p;
        temp= p->link;   
        p->link = q->link;   
        q->link = temp; 
        first=q;
    }
    else
    {
        follow2->link=p;
        follow1->link=q;
        temp= p->link;   
        p->link = q->link;   
        q->link = temp; 
    }
        
}
 
int main()
{
 cout<<"Enter the number of nodes to create "<<endl;

    int n,t;
    cin>>n;
    cout<<"enter values : "<<endl;
    while(n--)
    {
        cin>>t;
    insertion(t);
    }
    cout<<endl<<"The list is : "<<endl;
    display(first);
    cout<<endl;
    int x,y;
    cin>>x>>y;
    swap(x,y);
     display(first);
    return 0;
}
