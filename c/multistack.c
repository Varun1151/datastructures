#include<stdio.h>
#include<stdlib.h>
#define MS 100
#define MAXSTACKS 10
typedef struct
{
	int key;
}element;
element memory[MS];
int top[MAXSTACKS];
int boundary[MAXSTACKS];
int n=MAXSTACKS;

void stackfull(int i)
{
	printf("Stack %d is full\n",i);
}
void push(int i,element item)
{
	if(top[i]==boundary[i+1])
		stackfull(i);
	else
		memory[++top[i]]=item;
}
element stackempty(int i)
{
	element k;
	k.key=0;
	printf("Stack %d is empty\n",i);
	return k;
}
element pop(int i)
{
	if(top[i]==boundary[i])
		return stackempty(i);
	return memory[top[i]--];
}
void display(int i)
{
	int j;
	for(j=top[i];j>=boundary[i]+1;j--)
		printf("%d ",memory[j].key);
	printf("\n");
}
void main()
{
	int ch,i,j;
	element e;
	top[0]=boundary[0]=-1;
    for(j=1;j<n;j++)
	top[j]=boundary[j]=(MS/n)*j-1;
    top[j]=boundary[j]=MS-1;
	while(1)
	{
		printf("1)Push 2)pop 3)Display 4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter which stack to push element and the element\n");
			       scanf("%d%d",&i,&e.key);
				   push(i,e);
				   break;
			case 2:printf("Enter which stack to pop element\n");
			       scanf("%d",&i);
				   e=pop(i);
				   printf("Deleted element = %d\n",e.key);
				   break;
			case 3:printf("Enter which stack to display\n");
			       scanf("%d",&i);
				   display(i);
				   break;
			case 4:exit(0);
		}
	}
}