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
polyptr addp(polyptr a,polyptr b)
{
	int sum;
	polyptr rear,c,temp;
	rear=(struct node*)malloc(sizeof(struct node));
	c=rear;
	while(a&&b)
	{
		switch(COMPARE(a->expo,b->expo))
		{
			case 1:attach(a->coef,a->expo,&rear);
			       a=a->link;
				   break;
		    case 0:sum=a->coef+b->coef;
			       if(sum)
					   attach(sum,a->expo,&rear);
				   a=a->link;
				   b=b->link;
				   break;
		    case -1:attach(b->coef,b->expo,&rear);
			       b=b->link;
				   break;
		}
	}
	for(;a;a=a->link)
		attach(a->coef,a->expo,&rear);
	for(;b;b=b->link)
		attach(b->coef,b->expo,&rear);
	temp=c;
	c=c->link;
	free(temp);
	return c;
}
void attach(int a,int b,polyptr *ptr)
{
	polyptr temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->coef=a;
	temp->expo=b;
	temp->link=NULL;
	(*ptr)->link=temp;
	 *ptr=temp;
}
void main()
{
	polyptr a,b,c,temp,t1,t2;
	int m,n,i,temp1,temp2;
	printf("Enter number of terms in first and second polynomial\n");
	scanf("%d%d",&m,&n);
	a=(struct node*)malloc(sizeof(struct node));
	b=(struct node*)malloc(sizeof(struct node));
	t1=t2=a;
	printf("Enter first polynomial\n");
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		attach(temp1,temp2,&t1);
	}
	a=a->link;
	free(t2);
	t1=t2=b;
	printf("Enter second polynomial\n");
	for(i=m;i<m+n;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		attach(temp1,temp2,&t1);
	}
	b=b->link;
	free(t2);
	c=addp(a,b);
	printf("Sum of polynomials\n");
	for(;c->link;c=c->link)
	printf("%dx^%d+",c->coef,c->expo);
	printf("%dx^%d\n",c->coef,c->expo);
}
		