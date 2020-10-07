#include<iostream>
using namespace std;

class node{
 public:

	int data;
	node* next;

	node(int x){
	 data = x;
	 next = NULL;
     }
};



class linked_list{

public:

 node* head = NULL;

 void insertion(int x){

 node* curr= new node(x);


	if(head==NULL)
		head = curr;

	else{

		 node* temp = head;

		while(temp->next!=NULL){
			temp = temp->next;
		}

		temp->next = curr;

	}

}


node* reverse(){

	if(head==NULL)
		return head;

	node* ptr1 = head;
	node* ptr2 = head->next;
	node* ptr3 = NULL;

	ptr1->next = NULL;
	
	while(ptr2!=NULL){

       ptr3 = ptr2->next;

       ptr2->next = ptr1;

       ptr1 = ptr2;
       ptr2 = ptr3;
	}

	return ptr1;

}

void printing_list(node* temp){

 while(temp!=NULL){
 	cout<<temp->data<<"-->";
 	temp = temp ->next;
 }
 cout<<"NULL";

}


};

int main(){

	linked_list ll;

	int n; cin>>n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		ll.insertion(x);
	}

	cout<<"\nOriginal Linked List : ";

	ll.printing_list(ll.head);

	cout<<"\nReversed Linked List : ";

	node* head = ll.reverse();

	ll.printing_list(head);

	return 0;
}



