#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	int key;
}element;


struct node
{
	element data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *listptr;


void insert(listptr head)
{
	listptr nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter element\n");
	scanf("%d",&nn->data.key);
	nn->llink=head;
	nn->rlink=head->rlink;
	nn->rlink->llink=nn;
	head->rlink=nn;
}

element delete(listptr head)
{
	listptr del=head->rlink;
	element k=del->data;
	del->llink->rlink=del->rlink;
	del->rlink->llink=del->llink;
	free(del);
	return k;
}

void displtor(listptr head)
{
	listptr temp=head->rlink;
	for(;temp!=head;temp=temp->rlink)
		printf("%d     ",temp->data.key);
	printf("\n");
}


void disprtol(listptr head)
{
	listptr temp=head->llink;
	for(;temp!=head;temp=temp->llink)
		printf("%d\t",temp->data.key);
	printf("\n");
}	

void main()
{
	int ch;
	element item;
	listptr head=(struct node*)malloc(sizeof(struct node));
	head->data.key=-1;
	head->llink=head->rlink=head;
	while(1)
	{
		printf("1)Insert  2)Delete  3)Display L to R  4)Display R to L 5)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(head);
			        break;
			case 2: if(head->llink==head)
						printf("No elements\n");
				    else
					{
						item=delete(head);
						printf("Deleted element is %d\n",item.key);
			        }
					break;
	   		case 3: if(head->llink==head)
						printf("No elements\n");
				    else
						displtor(head);
			        break;
			case 4: if(head->llink==head)
						printf("No elements\n");
				    else
						disprtol(head);
					break;
			case 5: exit(0);
			default : printf("Invalid choice\n");
		}
	}
}
