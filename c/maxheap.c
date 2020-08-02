#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
typedef struct
{
	int key;
}element;
element heap[MAX_SIZE];
int n=0;
void push(element item)
{
	int i=++n;
	while(i!=1&&item.key>heap[i/2].key)
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=item;
}
element pop()
{
	int	parent,child;
	element	temp,item;
	if(n==0)
	{
		printf("Heap Empty\n");
		item.key=-1;
		return item;
	}
	item=heap[1];
	temp=heap[n--];
	parent=1;
	child=2;
	while(child<=n)
	{
		if(child<n&&heap[child].key<heap[child+1].key)
		child++;
		if(temp.key>=heap[child].key)
		break;
		heap[parent]=heap[child];
		parent=child;
		child=child*2;
	}
	heap[parent]=temp;
	return	item;
}
void display()
{
	int i;
	printf("Elements are\n");
	for(i=1;i<=n;i++)
	    printf("%d\t",heap[i].key);
	printf("\n");
}
int	main()
{
	int ch;
	element item;
	while(1)
	{
		printf("\n1)Push\t2)Pop\t3)Display\t4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to insert:");
				   scanf("%d",&item.key);
				   push(item);
				   break;
		
			case 3:
				if(n==0)
					printf("Heap Empty\n");
				else
					display();
				break;
			case 2:item=pop();
				   if(item.key!=-1)
					   printf("ElementDeleted:%d\n",item.key);
				   break;
			case 4:exit(0);
			default:printf("InvalidChoice\n");
		}
	}
}
	
