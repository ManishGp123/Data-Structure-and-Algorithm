#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Btree
{
	int data;
	struct Btree *left;
	struct Btree *right;	
}BTreeNode;

BTreeNode * CreateNode(int n)
{
	BTreeNode * temp1= (BTreeNode*)malloc(sizeof(BTreeNode));
	temp1->data = n;
	temp1->left = NULL;
	temp1 ->right = NULL;
	return(temp1);

}

BTreeNode * InsertNode(BTreeNode * root, int n)
{
	printf("address link = %p\n", root);	
	if(root == NULL)
	{
		root = CreateNode(n);
	}
	
	if(n > root->data)
		root->right = InsertNode(root->right, n);
	else if(n < root->data)
		root->left = InsertNode(root->left, n);

return root;
}

void inorder(BTreeNode * root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

void preorder(BTreeNode * root)
{
	if(root == NULL)
		return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);

}

void postorder(BTreeNode * root)
{
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t", root->data);

}

int count_Node(BTreeNode * root)
{
	if(!root)
	{
		return 0;	
	}
	int temp = 1+count_Node(root->left)+ count_Node(root->right);
	return temp;
}

int count_Leaf(BTreeNode * root)
{
	if(!root)
		return 0;
	else if(!(root->left) && !(root->right))

		return(1);
	else
	{
		return(count_Leaf(root->left) + count_Leaf(root->right));
	}
}

int count_NonLeaf(BTreeNode * root)
{
	if(!root)
		return 0;
	else if(!(root->left) && !(root->right))
		return 0;
	else
		return(1+count_NonLeaf(root->left) + count_NonLeaf(root->right));
}

int count_FullNode(BTreeNode * root)
{
	if(!root)
		return 0;
	else if(!(root->left) && (root->right))
		return 0;
	else
		return(count_FullNode(root->left) +count_FullNode(root->right)+((root->left && root->right)?1:0));
}

int Height_Tree(BTreeNode * root)
{
	if(!root)
		return 0;

	if(!(root->left) && !(root->right))
		return 0;

	int l,r;
	l = Height_Tree(root->left);
	r = Height_Tree(root->right);
	return(1 + ((l>r)?l:r));

}

int find_min(BTreeNode * root)
{
	while(root->left)
		root = root->left;
	return(root->data);
}

int find_max(BTreeNode * root)
{
	while(root->right)
		root=root->right;
	return(root->data);
}

BTreeNode * Delete_Node(BTreeNode * root,int n)
{
	int temp;
	BTreeNode *temp1;
	if(!root)
	{
		printf("Element not in the tree\n");
	}
	else if(n < root->data)
		root->left = Delete_Node(root->left, n);
	else if(n > root->data)
		root->right = Delete_Node(root->right, n);
	else
	{
		if(!(root->left) && !(root->right))
		{		
			free(root);
			return NULL;
		}

		else if(root->left && root->right)
		{
			temp = find_max(root->left);
			root->data = temp;
			root->left = Delete_Node(root->left, temp);
		}
		else
		{
			if(!root->left)
			{
				temp1 = root->right;
			}
			else
			{
				temp1 = root->left;
			}
			free(root);
			return(temp1);

		}
		
	}
	return root;
}
int main()
{	
		
	BTreeNode *root;
	root =NULL;
	int temp;
	int var1, choice;
	 while(1)
        {
                printf("\nEnter 1 for insert the node\n");
                printf("Enter 2 for traversing the node\n");
		printf("Enter 3 for preorder traversal\n");
		printf("Enter 4 for post order traversal\n");
                printf("Enter 5 for exit\n");
		printf("Enter 6 for count no of node\n");
		printf("Enter 7 for count no of leaf\n");
		printf("Enter 8 for count no of nonleaf\n");
		printf("Enter 9 for count no of Full Node\n");
		printf("Enter 10 for finding the height of tree\n");
		printf("Enter 11 for finding the min of tree\n");
		printf("Enter 12 for finding the max of tree\n");
		printf("Enter 13 for deleting the node of tree\n");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1:
				printf("enter the data you want to insert\n");
				scanf("%d", &var1);
                                root = InsertNode(root, var1);
                                break;
                        case 2:
                                inorder(root);
                                break;
			case 3: 
				preorder(root);
				break;
			case 4: 
				postorder(root);
				break;

                        case 5:
                                exit(0);
                                break;
			case 6:
				 temp=count_Node(root);
				printf("no of node = %d\n",temp);
				break;
			case 7: 
				temp = count_Leaf(root);
				printf("no of leaf node = %d\n",temp);
				break;
			case 8:
			
				temp = count_NonLeaf(root);
				printf("no of Non leaf node = %d\n", temp);
				break;
			case 9:
				temp = count_FullNode(root);
				printf("no of Full Node = %d\n",temp);
				break;
			case 10: 
				temp = Height_Tree(root);
				printf("Height of Tree = %d\n",temp);
				break;
			case 11:
				printf("min of the BST = %d\n", find_min(root));
				break;
			case 12:
				printf("max of the BST = %d\n", find_max(root));
				break;
			case 13:
			       	printf("Enter the data you want to delete\n");
				scanf("%d",&var1);	
				root = Delete_Node(root,var1);
				break;
                        default:
                                printf("input is not valid \n");
                                break;
                }
        }
	

return 0;
}
