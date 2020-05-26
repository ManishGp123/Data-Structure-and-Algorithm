#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode{
	int data;
	struct ListNode *next;
}SLLNode;

void DisplayList(SLLNode *head)
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	SLLNode *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p=p->next;
	}
}	

void DeleteNode(SLLNode **head1, int pos)
{
	SLLNode *p,*q;
	int k=1;
	if(*head1 == NULL)
	{printf("list is empty\n");}
	p = *head1;
	if(pos == 1)
	{
		*head1 = p->next;
		free(p);
		return;
	}
	else
	{
		while((p!=NULL) && (k < pos))
		{
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL)
		{printf("position doesn't exist\n");}
		else
		{
		q->next = p->next;
		free(p);
		return;
		}
	}
}
void InsertLinkList(SLLNode **head1, int pos)
{
	int n;
	int k=1;	
	SLLNode *p, *q, *newNode;
	printf("enter the data\n");
	scanf("%d", &n);
	newNode = (SLLNode*)malloc(sizeof(SLLNode));
	if(!newNode)
	{
		printf("memory error\n");
		return;
			
	}
	newNode->data = n;
	p = *head1;
	if(pos==1)
	{
		newNode->next = p;
		*head1 = newNode;
	}
	else
	{
		while(p!=NULL && k<pos)
		{
			q=p;
			p=p->next;
			k=k+1;
		}
		q->next=newNode;
		newNode->next = p;
	}

}

int main()
{

	printf("try to learn linked list\n");
	SLLNode *head;
	head =NULL;
	DisplayList(head);
	int choice, pos;
	while(1)
	{
		printf("enter 1 for inserting into the list\n");
		printf("enter 2 for display the result\n");
		printf("enter 3 for deleting the node\n");
		printf("enter 4 for exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("enter the position\n");
				scanf("%d", &pos);
				InsertLinkList(&head, pos);
				break;
			case 2:
				DisplayList(head);
				break;
			case 3:
				printf("enter node positon\n");
				scanf("%d", &pos);
				DeleteNode(&head, pos);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("no input provided\n");
				break;
		}
	}

	DisplayList(head);

return 0;
}
