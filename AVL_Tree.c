#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count;

//define of a node
typedef struct AVL_NODE
{
	int data;
	struct AVL_NODE * right;
	struct AVL_NODE * left;
}AVL_Node;

//program for finding the height
int height_tree(AVL_Node * root)
{
	int l,r;
	if(!root)
		return 0;
	else if(!(root->left) && !(root->right))
		return 1;
	else
		l = height_tree(root->left);
		r = height_tree(root->right);
		if(l>r)
			return(1+l);
		else
			return(1+r);
}

//program for Left Left rotation
AVL_Node * LL_rotation(AVL_Node *root)	
{
	AVL_Node * temp;
	temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return(temp);
}

//Program for Right Right rotation
AVL_Node * RR_rotation(AVL_Node * root)
{
	AVL_Node * temp;
	temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return(temp);	
}

//Program for Left Right rotation
AVL_Node * LR_rotation(AVL_Node * root)
{

	root->left = RR_rotation(root->left);
	return(LL_rotation(root));

}

//Program for Right Left Rotation
AVL_Node * RL_rotation(AVL_Node * root)
{
	root->right = LL_rotation(root->right);
	return(RR_rotation(root));

}

//for finding the Balance Factor
int BF(AVL_Node * root)
{
	return((height_tree(root->left) - height_tree(root->right)));
}

//for inserting into the node
AVL_Node * insert_Node(AVL_Node * root,int n)
{
	//if not root 
	if(!root)
		{
			root = malloc(sizeof(AVL_Node));
			if(!root)
				printf("memory Error!\n");
			else
			{
				root->data = n;
				root->left = NULL;
				root->right = NULL;
			}
		}
	// if some data is there
	else if(n< root->data)
	{
		root->left = insert_Node(root->left, n);
		
		if((height_tree(root->left)-height_tree(root->right))==2)
		//if(BF(root)==2)
		{
			printf("height left = %d\t height right =%d\n",height_tree(root->left),height_tree(root->right));
			if(n < (root->left->data))
			{	printf("LL performed\n");
				root = LL_rotation(root);
			}
			else
				root = LR_rotation(root);		
		}
	}
	else if(n > root->data)
	{
		root->right = insert_Node(root->right, n);
		if((height_tree(root->right)-height_tree(root->left))==2)
		{
			if(n>(root->right->data))
			{
				printf("RR rotation performed\n");
				root  = RR_rotation(root);
			}
			else
				root = RL_rotation(root);
		}
	}

	return(root);

}

//inorder traversal
void inorder(AVL_Node * root)
{
	if(root == NULL)
	{
	//	printf("Empty tree\n");
		return;
	}
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

//preorder traversal
 void preorder(AVL_Node * root)
{
	if(root == NULL)
	{
	//	printf("Empty tree\n");
		return;
	}
	printf("%d\t", root->data);
	preorder(root->left);
	preorder(root->right);
}

//
AVL_Node * Build_HB(int h)
{
	int n;
	AVL_Node * temp;
	temp = (AVL_Node*)malloc(sizeof(AVL_Node));
	if(h == 0)
		return NULL;
	temp ->left = Build_HB(h-1);
	printf("Enter data\n");
	scanf("%d",&n);
	temp->data =n;
	temp->right = Build_HB(h-1);
	return temp;
}

//menu driven program

int main()
{
	int h;
	int choice,n;
	int temp;
	AVL_Node * root;
	AVL_Node * root1;
	root = NULL;
	printf("\nlearning AVL implementation\n");
	while(1)
	{
		printf("\nEnter 1 for inserting into AVL\n");
		printf("Enter 2 for traverese the AVL Tree\n");
		printf("Enter 3 for exit\n");
		printf("Enter 4 for finding the height\n");
		printf("Enter 5 for inroder traverseing\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data you want to enter \n");
				scanf("%d", &n);
				root = insert_Node(root,n);
				break;
			case 2:
				preorder(root);
				break;
			case 3: 
				exit(1);
				break;
			case 4:
				temp = height_tree(root);
				printf("height of tree = %d\n", temp-1);
				break;
			case 5: 
				inorder(root);
				break;
			case 6:
				printf("Enter height\n");
				scanf("%d", &h);
				root1 =  Build_HB(h);
				break;
			default:
				printf("Enter data is not valid\n");
				break;
		}
	}
return 0;
}
