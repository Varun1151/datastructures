#include<stdio.h>
typedef struct
{
	int row;
	int col;
	int val;
}term;
void transpose(term a[],term b[])
{
	int i,j,n=a[0].val,cb=1;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].val=n;
	for(i=0;i<a[0].col;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j].col==i)
			{
				b[cb].row=a[j].col;
				b[cb].col=a[j].row;
				b[cb].val=a[j].val;
				cb++;
			}
		}
	}
}
void main()
{
	term a[20],b[20];
	int i;
	printf("Enter no of rows,columns,elements in sparse matrix\n");
	scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
	printf("Enter row index,column index,element in sparse matrix\n");
	for(i=1;i<=a[0].val;i++)
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
	transpose(a,b);
	printf("Transpose of sparse matrix is \n");
	for(i=0;i<=a[0].val;i++)
		printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
}
	