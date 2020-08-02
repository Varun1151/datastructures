#include<stdio.h>
#define SWAP(a,b,c) c=a,a=b,b=c
void selsort(int a[],int n)
{
	int i,j,minid,t;
	for(i=0;i<n;i++)
	{
		minid=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[minid])
				minid=j;
		}
		SWAP(a[i],a[minid],t);
	}
}
void main()
{
	int a[100],n,i;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Original array\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	selsort(a,n);
	printf("\nSorted array\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}