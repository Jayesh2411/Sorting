#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int adjacent[MAX][MAX];
int visited[MAX];
int top_sort[MAX];
int queue[MAX];
int front = -1, rear = 0;

void create_graph(int num)	{
	int i, origin, destination;
	for(i = 0; i <= num*num -1; i++)	{
		printf("\nEnter the origin and destination of graph: or -1 and -1 to exit");
		scanf("%d",&origin);
		scanf("%d",&destination);
		if((origin == -1) && (destination == -1))
		{
			break;
		}
		if(origin >= num || destination >= num || origin < 0 || destination < 0)
		{
			printf("Edge Co-ordinates are Invalid\n");
			i--;
		}
	}
}

int find_indegree(int vertex,int num)	{
	int indegree = 0;
	for(int i = 0; i <=num; i++)	{
		if(adjacent[vertex][i] == 1)
			indegree++;
	}
	return indegree;
}	
void add(int vertex)	{
	int i;
	if(rear == MAX-1)	
	{	
		printf("Overflow\n");
	}
	else if(front == -1)
		front = 0;
	else		
		queue[++rear] = vertex;
}
int isEmpty();
int del()	{
		int temp;
	if( isEmpty() )	{
		printf("Underflow!\n");
		exit(1);
		}
	else	{
			temp = queue[front];
			++front;
			return temp;
		}

}
int isEmpty()	{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int main()
{
	int count = 0,num,origin,destination,vertex,i,indegree[MAX];
	printf("\nEnter no. of vertices: ");
	scanf("%d",&num);
	create_graph(num);
	for(i = 0;i <= num; i++)	{
		indegree[i] = find_indegree(i,num);		
		if(indegree[i] == 0)
			add(i);
	}
	i = 0;
	while(!isEmpty() && count < num)	{
		vertex = del();
		top_sort[++count] = vertex;
		for(i = 0; i <= num; i++)	{
			if(adjacent[vertex][i] == 1)	{
				adjacent[vertex][i] = 0;
				indegree[i] = indegree[i] - 1;
			}
			if(indegree[i] == 0)	
				add(i);
		}
	}
	if(count < num)
		printf("The graph is not a DAG\n");
	for(i = 0; i <= num; i++)
		printf("%d",top_sort[i]);
}
	 
