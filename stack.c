#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DETAILS
{
	int age;
	char name[20];
}Details;

typedef struct STACK
{
	int top;
	int capacity;
	Details *array;
}Stack;

Stack * CreateStack(int size)
{
	Stack *temp;
	temp = (Stack*)malloc(sizeof(Stack));
	temp->top= -1;
	temp->capacity = size;
	temp->array = malloc(sizeof(Details)*size);
	return temp;
}
int IsFull(Stack *S)
{
	if((S->capacity)-1 == (S->top))
	{
		return 1;
	}
	else 
		return 0;
}

int IsEmpty(Stack *S)
{
	if(S->top == -1)
	{
		return 1;
	}
	else
		return 0;
}

void Push(Stack *S)
{
	
	if(!(IsFull(S)))
	{	
		int data;
		char data1[20];
		char temp1;
		S->top = S->top +1;
		printf("Enter the age you want to push\n");
		scanf("%d", &data);
		//printf("enter any character\n");
		scanf("%c", &temp1);
		printf("Enter the name\n");
		scanf("%[^\n]", S->array[S->top].name);
		S->array[S->top].age = data;
		
	}
	else
		
	{
		printf("Stack is full\n");
		return;
	}
}
void Pop(Stack *S)
{
	if(!(IsEmpty(S)))
	{

		printf("The name and age is =%s and %d", S->array[S->top].name, S->array[S->top].age);
		printf("\n");
		S->top = S->top -1;
	}
	else
	{
		printf("Stack is Empty\n");
		return;
	}
}

int main()
{

	Stack *S;
	int size;
	int choice;
	printf("enter the size of Stack\n");
	scanf("%d", &size);
	S=CreateStack(size);
	printf("%d", S->capacity);

	while(1)
	{
		printf("\nEnter 1 for Push the data\n");
		printf("Enter 2 for pop the data\n");
		printf("Enter 3 for exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				Push(S);
				break;
			case 2:
				Pop(S);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("input is not valid \n");
				break;
		}
	}
	
return 0;	
}
