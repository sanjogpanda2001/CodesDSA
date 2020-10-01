#include <iostream>

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
void insertion(node* n,int v)
{
    int d=0;
   node* temp=new node;
   temp->data=v;
   temp->link=NULL;
    node* follow;
    node* p;
    if(c==0)
    {
        first=temp;
        c++;
    }
    else if(c==1)
    {
        if(temp->data>first->data)
        first->link=temp;
        else
        {
            temp->link=first;
            first=temp;
        }
        c++;
    }
    else
    {
        p=first;
        if(first->data>temp->data)
        {
            temp->link=p;
            first=temp;
        }
        else
        {
            while(p && p->data<v)
            {
                follow=p;
                p=p->link;
                if(p==0)
                d=1;
            }
            if( d!=1)
            {
                if(p->data>v)
                {
                temp->link=follow->link;
                follow->link=temp;}
            }
            else if(d==1)
            {
                follow->link=temp;
            }
        }   
    }
}
int main()
{
    cout<<"enter the number of nodes :"<<endl;
    int n;
    cin>>n;
    while(n--)
    {
        cout<<"Enter Value :"<<endl;
        int v;
        cin>>v;
insertion(first,v);
cout<<endl<<"Sorted List is : "<<endl;
display(first);}
    return 0;
}
