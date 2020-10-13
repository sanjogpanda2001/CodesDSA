//bst
//instet
# include <stdio.h>
# include <malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;
void find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;
       if(root==NULL)  /*tree empty*/
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->data) /*item is at root*/
	{
		*loc=root;
		*par=NULL;
		return;
	}
	/*Initialize ptr and ptrsave*/
	if(item<root->data)
		ptr=root->left;
	else
		ptr=root->right;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->data)
		{       *loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	 }/*End of while */
	 *loc=NULL;   /*item not found*/
	 *par=ptrsave;
}/*End of find()*/




void case_a(struct node *par,struct node *loc )
{
	if(par==NULL) /*item to be deleted is root node*/
		root=NULL;
	else
		if(loc==par->left)
			par->left=NULL;
		else
			par->right=NULL;
}/*End of case_a()*/

void case_b(struct node *par,struct node *loc)
{
	struct node *child;

	/*Initialize child*/
	if(loc->left!=NULL) /*item to be deleted has left */
		child=loc->left;
	else                /*item to be deleted has right */
		child=loc->right;

	if(par==NULL )   /*Item to be deleted is root node*/
		root=child;
	else
		if( loc==par->left)   /*item is left of its parent*/
			par->left=child;
		else                  /*item is right of its parent*/
			par->right=child;
}/*End of case_b()*/

void case_c(struct node *par,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*parsuc;

	/*Find inorder successor and its parent*/
	ptrsave=loc;
	ptr=loc->right;
	while(ptr->left!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->left;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->left==NULL && suc->right==NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);

	if(par==NULL) /*if item to be deleted is root node */
		root=suc;
	else
		if(loc==par->left)
			par->left=suc;
		else
			par->right=suc;

	suc->left=loc->left;
	suc->right=loc->right;
}/*End of case_c()*/
int del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	find(item,&parent,&location);
	if(location==NULL)
	{
		printf("Item not present in tree");
		return 0;
	}

	if(location->left==NULL && location->right==NULL)
		case_a(parent,location);
	if(location->left!=NULL && location->right==NULL)
		case_b(parent,location);
	if(location->left==NULL && location->right!=NULL)
		case_b(parent,location);
	if(location->left!=NULL && location->right!=NULL)
		case_c(parent,location);
	free(location);
}/*End of del()*/

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}/*End of preorder()*/

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d  ",ptr->data);
		inorder(ptr->right);
	}
}/*End of inorder()*/

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d  ",ptr->data);
	}
}/*End of postorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->right, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->data);
		display(ptr->left, level+1);
	}/*End of if*/
}/*End of display()*/
int height(struct node *x)
{
int a=0,b=0;
    if(x!=0)
    {
a=height(x->left);
b=height(x->right);
	
if(a>b)
return a+1;
else
return b+1;
	}
}
struct node  *mirror(struct node *root ,struct node *x)// still not working

{
	if(root!=NULL)
	{
x->data=root->data;

if(root->left!=NULL)
{ 
    struct node *left;
left=(struct node *)malloc(sizeof(struct node));
x->right=left;
x->right->right=x->right->left=NULL;
mirror(root->left,x->right);

}
if(root->right!=NULL)
{ 
    struct node *right;
right=(struct node *)malloc(sizeof(struct node));
x->left=right;
x->left->left=x->left->right=NULL;
mirror(root->right,x->left);

}
	}
else
 return 0;
	

return x;
}

int main()
{
	int choice,num;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.Display\n");
	    printf("7.height\n");
		printf("9.mirror\n");

		printf("8.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			postorder(root);
			break;
		 case 6:
			display(root,1);
			break;
		 case 7:
		 printf("the height is %d",height(root));
            break;
			case 9:
			{
				struct node *x;
x=(struct node *)malloc(sizeof(struct node));
root=mirror(root,x);
break;
			}
			
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/















// struct node* new_node(int x)
// {
//     struct node *p;
//     p = malloc(sizeof(struct node));
//     p->data = x;
//     p->left = NULL;
//     p->right = NULL;

//     return p;
// }

// struct node* insert( struct node* root, int data ) 
// {
    
//     if(root==NULL)
//         return new_node(data);
//     else if(data>root->data) 
//         root->right = insert(root->right, data);
//     else 
//         root->left = insert(root->left,data);
//     return root;
// }