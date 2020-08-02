#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node *stackptr;
void push(stackptr *top,int item)
{
	stackptr temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=*top;
	*top=temp;
}
int pop(stackptr *top)
{
	stackptr temp=*top;
	int k=temp->data;
	*top=temp->link;
	free(temp);
	return k;
}
void display(stackptr top)
{
	for(;top;top=top->link)
		printf("%d ",top->data);
	printf("\n");
}
void main()
{
	stackptr top=NULL;
	int ch,item;
	while(1)
	{
		printf("1)push  2)pop  3)display  4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element to be inserted\n");
					scanf("%d",&item);
					push(&top,item);
					break;
			case 2: if(top==NULL)
						printf("Stack is empty\n");
					else
					{
						item=pop(&top);
						printf("Deleted element is %d\n",item);
					}
					break;
			case 3: if(top==NULL)
						printf("Stack is empty\n");
					else
						display(top);
					break;
			case 4: exit(0);
			default : printf("Invalid choice\n");
		}
	}
}
	