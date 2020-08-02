#include<stdio.h>
typedef struct
{
	int row;
	int col;
	int val;
}term;
void transpose(term a[],term b[])
{
	int rowterms[20],sp[20];
	int i,j,not=a[0].val,noc=a[0].col;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].val=not;
	for(i=0;i<noc;i++)
		rowterms[i]=0;
    for(i=1;i<=not;i++)
		rowterms[a[i].col]++;
	sp[0]=1;
	for(i=1;i<noc;i++)
		sp[i]=sp[i-1]+rowterms[i-1];
	for(i=1;i<=not;i++)
	{
		j=sp[a[i].col]++;
		b[j].row=a[i].col;
		b[j].col=a[i].row;
		b[j].val=a[i].val;
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
	