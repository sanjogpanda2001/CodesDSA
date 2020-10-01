#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};
Node* head=NULL;
Node* end=NULL;

void creatingLL(int arr[])
{
for(int i=0;i<n;i++)
  {
     if(end==NULL)
     {
     head=end=new Node;
     end->data=arr[i];
     end->next=NULL;
     }
     else
     {
     
     Node* temp=new Node;
     temp->data=arr[i];
     temp->next=NULL;
     end->next=temp;
     end=temp;
     }
     
  }
}

void printingLL()
{
if(head==NULL)
return;

Node* p=head;
while(p!=NULL)
{
  cout<<p->data<<" ";
  p=p->next;
}

}

void deleteHeadNode()
{
if(head==NULL)
return;

Node* p=head->next;
delete head;
head=p;
}


int main()
{
  
  
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  creatingLL(arr);
  
  printingLL();
 
deleteHeadNode()
 
return 0;
}
