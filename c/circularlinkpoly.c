#include<stdio.h>
#define COMPARE(x,y) (x>y)?1:(x<y)?-1:0
#include<stdlib.h>
struct node
{
	int coef,expo;
	struct node *link;
};
typedef struct node *polyptr;
void attach(int,int,polyptr*);
polyptr cpad(polyptr a,polyptr b)
{
	int sum,done=0;
	polyptr starta,c,lastc;
	starta=a;
	a=a->link;
	b=b->link;
	c=(struct node*)malloc(sizeof(struct node));
	c->expo=-1;
	lastc=c;
	do
	{
		switch(COMPARE(a->expo,b->expo))
		{
			case 1:attach(a->coef,a->expo,&lastc);
			       a=a->link;
				   break;
		    case 0:if(starta==a)
				   done=1;
			       else
				   {
					sum=a->coef+b->coef;
					if(sum)
					   attach(sum,a->expo,&lastc);
					a=a->link;
					b=b->link;
				   }
				   break;
		    case -1:attach(b->coef,b->expo,&lastc);
			       b=b->link;
				   break;
		}
	}
	while(!done);
	lastc->link=c;
	return c;
}
void attach(int a,int b,polyptr *ptr)
{
	polyptr temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->coef=a;
	temp->expo=b;
	(*ptr)->link=temp;
	 *ptr=temp;
}
void main()
{
	polyptr a,b,c,t;
	int m,n,i,temp1,temp2;
	printf("Enter number of terms in first and second polynomial\n");
	scanf("%d%d",&m,&n);
	a=(struct node*)malloc(sizeof(struct node));
	b=(struct node*)malloc(sizeof(struct node));
	a->expo=-1;
	b->expo=-1;
	t=a;
	printf("Enter first polynomial\n");
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		attach(temp1,temp2,&t);
	}
	t->link=a;
	
    t=b;
	printf("Enter second polynomial\n");
	for(i=m;i<m+n;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		attach(temp1,temp2,&t);
	}
	t->link=b;
	c=cpad(a,b);
	
	printf("Polynomial 1 : ");
	for(t=a->link;t->link!=a;t=t->link)
	printf("%dx^%d+",t->coef,t->expo);
	printf("%dx^%d\n",t->coef,t->expo);
	
	printf("Polynomial 1 : ");
	for(t=b->link;t->link!=b;t=t->link)
	printf("%dx^%d+",t->coef,t->expo);
	printf("%dx^%d\n",t->coef,t->expo);
	
	printf("Sum of polynomials : ");
	for(t=c->link;t->link!=c;t=t->link)
	printf("%dx^%d+",t->coef,t->expo);
	printf("%dx^%d\n",t->coef,t->expo);
}
		