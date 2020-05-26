#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode{

	int data;
	struct ListNode *next;
	struct ListNode *prev;
}DLLNode;

void DeleteNode(DLLNode **head1, int pos)
{
	DLLNode *p;
	int k=1;
	p = *head1;
	if(head1 == NULL)
	{
		printf("list is empty\n");

	}

	if(pos == 1)
	{
		*head1 = p->next;
		free(p);
		return;
	}
	else
	{
		while((k<pos) && (p->next!=NULL))
		{
			k++;
			p=p->next;
		}

		if(p->next == NULL)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			return;
		}
		else
		{
			printf(" not a valid position\n");
		}
			
	}
}
void Display(DLLNode *head)
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	DLLNode *p;
	p = head;

	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p=p->next;
	}
}

void InsertNode(DLLNode **head1, int pos)
{
	DLLNode *p, *q, *NewNode;
	int n, k = 1;
	NewNode = (DLLNode*)malloc(sizeof(DLLNode));
	if(!NewNode)
	{
		printf("Memory Error\n");
	}
	printf("Enter the data for new Node\n");
	scanf("%d", &n);
	
	p = *head1;
	NewNode->data =  n;
	if(pos == 1)
	{
		NewNode->prev = NULL;
		NewNode->next = *head1;
		if(*head1)
		{
			(*head1)->prev = NewNode;

		}
		*head1 = NewNode;
	}
	else 
	{
		while((p->next!=NULL) && (k<pos))
		{
		              
			p=p->next;
			k=k+1;
		}

		if(p->next == NULL)
		{
			NewNode->next = NULL;
			NewNode->prev = p;
			p->next = NewNode;
		}
		else
		{
			NewNode ->next = p;
			NewNode ->prev = p->prev;
			p->prev = NewNode;
			p->prev->next = NewNode;	
		
		}
		
	}

}

void CountNode(DLLNode *head)
{
	int count=0;
	DLLNode *p;
	p= head;
	if(head == NULL)
	{
		printf("list is empty\n");
	}
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	printf("No of node in following list is =%d\n", count);
}
int main()
{
	 printf("try to learn linked list\n");
        DLLNode *head;
        head =NULL;
        Display(head);
        int choice, pos;
        while(1)
        {
                printf("enter 1 for inserting into the list\n");
                printf("enter 2 for display the result\n");
                printf("enter 3 for deleting the node\n");
		printf("enter 4 for count the no of node\n");
                printf("enter 5 for exit\n");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1:
                                printf("enter the position\n");
                                scanf("%d", &pos);
                                InsertNode(&head, pos);
                                break;
                        case 2:
                                Display(head);
                                break;
                        case 3:
                                printf("enter node positon\n");
                                scanf("%d", &pos);
				DeleteNode(&head, pos);
				break;
			case 4:
				CountNode(head);
				break;
                        case 5:
                                exit(0);
                                break;
                        default:
                                printf("no input provided\n");
                                break;
                }
        }
return 0;	
}
