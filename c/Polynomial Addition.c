#include<stdio.h>
#define COMPARE(x,y) (x>y?1:((x<y)?-1:0)
typedef struct
{
	int coef;
	int expo;
}poly;
poly term[100];
void add(int,int,int,int,int*,int*);
void attach(int,int);
int avail=0;
void main()
{
	int sa,fa,sb,fb,sd,fd,i,m,n;
	printf("Enter number of terms in 1st and 2nd polynomial\n");
	scanf("%d%d",&m,&n);
	sa=0;fa=m-1;
	sb=m;fb=m+n-1;
	avail=fb+1;
	printf("Enter coef,expo of all terms in 1st polynomial\n");
    for(i=sa;i<=fa;i++)
	   scanf("%d%d",&term[i].coef,&term[i].expo);
    printf("Enter coef,expo of all terms in 2nd polynomial\n");
    for(i=sb;i<=fb;i++)
	   scanf("%d%d",&term[i].coef,&term[i].expo);
    printf("Sum of polynomials\n");
    add(sa,fa,sb,fb,&sd,&fd);
	for(i=sd;i<fd;i++)
	   printf("%dx^%d+",term[i].coef,term[i].expo);
    printf("%dx^%d",term[i].coef,term[i].expo);
}
void add(int sa,int fa,int sb,int fb,int *sd,int *fd)
{
	int c;
	*sd=fb+1;
	while(sa<=fa&&sb<=fb)
	{
	    switch(COMPARE(term[sa].expo,term[sb].expo)))
		{
			case 1:attach(term[sa].coef,term[sa].expo);
			       sa++;
				   break;
			case 0:c=term[sa].coef+term[sb].coef;
			       if(c)
					   attach(c,term[sa].expo);
				   sa++;
				   sb++;
				   break;
		    case -1:attach(term[sb].coef,term[sb].expo);
			       sb++;
				   break;
		}
	}
	for(;sa<=fa;sa++)
		attach(term[sa].coef,term[sa].expo);
	for(;sb<=fb;sb++)
		attach(term[sb].coef,term[sb].expo);
	*fd=avail-1;
}
void attach(int x,int y)
{
	term[avail].coef=x;
	term[avail++].expo=y;
}