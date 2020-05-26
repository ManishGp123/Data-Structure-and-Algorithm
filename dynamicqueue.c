//Queue implementation
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
        temp->front=-1;
        temp->rear =-1;
        temp->array = malloc(sizeof(int)*n);
        temp->capacity = n;

return temp;
}

int isFull(queue * Q)
{
        if(((Q->rear+1)%(Q->capacity)) == Q->front)
        {
                return 1;
        }
        else
                return 0;
}


int isEmpty(queue *Q)
{
    if(Q->front == -1)
        {
                printf("Q is empty\n");
                return 1;
                          }
        else
                return 0;
}

void Resize(queue * Q)
{
	int i=0;
	int size = Q->capacity;
	Q->capacity = Q->capacity*2;
	Q->array = realloc(Q->array, Q->capacity);
	if(!(Q->array))
	{
		printf("Memory error\n");
		return;
	}
	if(Q->front > Q->rear)
	{
		for(i =0; i<(Q->front); i++)
		{
			Q->array[i+size] = Q->array[i];
		}
		Q->rear = Q->rear+size;
	}

}
void enqueue(queue* Q,int data)
{

                if(isFull(Q))
                {

                        Resize(Q);
   		}
                
                        Q->rear = ((Q->rear+1) % (Q->capacity));
                        Q->array[Q->rear] = data;

                        if(Q->front == -1)
                                Q->front = Q->rear;
}

void dequeue(queue * Q)
{
        if(isEmpty(Q))
        {
                return;
        }
        else
        {
                printf("data is %d\n",Q->array[Q->front]);
                if(Q->front == Q->rear)
                        Q->front = Q->rear = -1;
                else
                        Q->front = (Q->front+1)%(Q->capacity);
        }

}

void Delete(queue * Q)
{
        if(Q)
        {
                if(Q->array)
                        free(Q->array);
                free(Q);
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
                printf("Enter 3 for delete the queue\n");
                printf("Enter 4 for exit\n");
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
                                Delete(Q);
                                break;
                        case 4:
                                exit(0);
                                break;
                        default:
                         	printf("not valid input\n");
                                break;


                }
        }
return 0;
}

