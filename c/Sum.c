#include<stdio.h>
#include<stdlib.h>
int **input(int **a,int,int);
int **sum(int **a,int **b,int **c,int,int);
void display(int **a,int,int);
void main()
{
	int **x,**y,**z,m,n;
	printf("Enter rowsize and column size\n");
	scanf("%d%d",&m,&n);
	printf("Enter 1st matrix\n");
	x=input(x,m,n);
	printf("Enter 2nd matrix\n");
	y=input(y,m,n);
	z=sum(x,y,z,m,m);
	printf("1st matrix\n");
	display(x,m,n);
	printf("1st matrix\n");
	display(y,m,n);
	printf("Resultant matrix\n");
	display(z,m,n);
}
int **input(int **a,int m,int n)
{
	int i,j;
	a=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	a[i]=(int*)malloc(n*sizeof(int));
    for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	return a;
}
int **sum(int **a,int **b,int **c,int m,int n)
{
	int i,j;
	c=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	c[i]=(int*)malloc(n*sizeof(int));
    for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			c[i][j]=a[i][j]+b[i][j];
	return c;
}
void display(int **a,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
