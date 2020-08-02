#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}element;
int top=-1,capacity=1;element *stack;
void stackfull()
{
	stack=realloc(stack,2*capacity*sizeof(element));
	capacity*=2;
}
element stackempty()
{
	printf("Stack empty\n");
	element x;
	x.key=0;
	return x;
}
void push(element x)
{
	if(top==capacity)
		stackfull();
	stack[++top]=x;
}
element pop()
{
	if(top==-1)
		return stackempty();
	return stack[top--];
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
		printf("%d\n",stack[i].key);
}
void main()
{
	int c;element ele;
	stack=(element*)malloc(sizeof(element));
	while(1)
	{
		printf("1)PUSH 2)POP 3)DISPLAY 4)EXIT\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter element\n");
			       scanf("%d",&ele.key);
			       push(ele);
			       break;
			case 2:ele=pop();
                               printf("Deleted element=%d\n",ele.key);
			       break;	
                        case 3:display();
			       break;
			case 4:exit(0);
		}
	}
}
			
		