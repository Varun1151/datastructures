#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUES 10

typedef struct
{
	int key;
}element;
struct node
{
	element data;
	struct node *link;
};
typedef struct node *queueptr;
queueptr front[MAXQUEUES];
queueptr rear[MAXQUEUES];
void addq(int i,element item)
{
	queueptr temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=NULL;
	if(rear[i]!=NULL)
		rear[i]->link=temp;
	rear[i]=temp;
	if(front[i]==NULL)
		front[i]=temp;
}
element deleteq(int i)
{
	queueptr temp=front[i];
	element k=temp->data;
	front[i]=temp->link;
	free(temp);
	return k;
}
void display(int i)
{
	queueptr temp=front[i];
	if(!(front[i]))
		printf("Queue empty\n");
	else
	{
		for(;temp;temp=temp->link)
			printf("%d ",temp->data.key);
		printf("\n");
	}
}
void main()
{
	int ch,i,n;
	element item;
	printf("Enter how many queues\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		front[i]=NULL;
		rear[i]=NULL;
	}
	while(1)
	{
		printf("1)Insert  2)Delete  3)display  4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter queue number and element to be inserted\n");
					scanf("%d%d",&i,&item.key);
					addq(i,item);
					break;
			case 2: printf("Enter queue number\n");
			        scanf("%d",&i);
					if(front[i]==NULL)
						printf("queue is empty\n");
					else
					{
						item=deleteq(i);
						printf("Deleted element is %d\n",item.key);
					}
					break;
			case 3: printf("Enter queue number\n");
			        scanf("%d",&i);
					display(i);
					break;
			case 4: exit(0);
			default : printf("Invalid choice\n");
		}
	}
}
	