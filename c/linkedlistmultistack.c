#include<stdio.h>
#include<stdlib.h>
#define MAXSTACKS 10

typedef struct
{
	int key;
}element;
struct node
{
	element data;
	struct node *link;
};
typedef struct node *stackptr;
stackptr top[MAXSTACKS];
void push(int i,element item)
{
	stackptr temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=top[i];
	top[i]=temp;
}
element pop(int i)
{
	stackptr temp=top[i];
	element k=temp->data;
	top[i]=temp->link;
	free(temp);
	return k;
}
void display(int i)
{
	stackptr temp=top[i];
	for(;temp;temp=temp->link)
		printf("%d ",temp->data.key);
	printf("\n");
}
void main()
{
	int ch,i,n;
	element item;
	printf("Enter how many stacks\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		top[i]=NULL;
	while(1)
	{
		printf("1)push  2)pop  3)display  4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter stack number and element to be inserted\n");
			             scanf("%d%d",&i,&item.key);
			             push(i,item);
			             break;
			case 2: printf("Enter stack number\n");
			             scanf("%d",&i);
			             if(top[i]==NULL)
			             printf("Stack is empty\n");
			             else
			             {
					item=pop(i);
					printf("Deleted element is %d\n",item.key);
			             }
			             break;
	   		case 3: printf("Enter stack number\n");
	 		             scanf("%d",&i);
			             if(top[i]==NULL)
					printf("Stack is empty\n");
			             else
				               display(i);
		                           break;
			 case 4: exit(0);
			 default : printf("Invalid choice\n");
		}
	}
}
