#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5;
typedef struct Queue
{
	int front;
	int rear;
	int capacity;
	int *array;
	
}queue;
queue * create_queue(int n)
{
	queue * temp= (queue*)malloc(sizeof(queue));
	if(!temp)
	{
		printf("memory error\n");
	}
	temp->front=0;
	temp->rear =0;
	temp->array = malloc(sizeof(int)*n);
	temp->capacity = n;
return temp;
}

int isFull(queue * Q)
{
        if(Q->front == Q->rear)
	{
		printf("memory is full\n");
         	return 1;
	}
        else
                return 0;
}


int isEmpty(queue *Q)
{
	if(Q->front == Q->rear)
	{
		printf("Q is empty\n");
		return 1;
	}
	else
		return 0;
}
void enqueue(queue* Q,int data)
{
	Q->rear = (Q->rear +1)%(Q->capacity);
		if(isFull(Q))
		{
			if(Q->rear == 0)
				Q->rear = (Q->capacity)-1;
			else
				Q->rear = Q->rear-1;
			return;
		}
		else
		{
			Q->array[Q->rear] = data;
			return;
		}
}
void dequeue(queue * Q)
{
	if(isEmpty(Q))
	{
		return;
	}
	else
	{
		Q->front = (Q->front+1) % (Q->capacity);
		printf("data is %d\n",Q->array[Q->front]);
		return;
	}

}

int main()
{
	queue * Q;
	Q =NULL;
	int n,choice,data;
	printf("Enter the size of queue\n");
	scanf("%d",&n);
	Q = create_queue(n);
	while(1)
	{
		printf("\nEnter 1 for enqueue data in queue\n");
		printf("Enter 2 for dequeue the data\n");
		printf("Enter 3 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data for enque\n");
				scanf("%d",&data);
				enqueue(Q,data);
				break;
			case 2:
				dequeue(Q);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("not valid input\n");
				break;

		
		}
	}
	printf("%d",Q->capacity);
return 0;
}
