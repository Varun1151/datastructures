#include<stdio.h>
#define COMPARE(x,y) (x>y)?1:(x<y)?-1:0
int bsearch(int a[],int k,int l,int h)
{
	int m,c;
	if(l<=h)
	{
	    m=(l+h)/2;
		switch(COMPARE(a[m],k))
		{
			case 1:return bsearch(a,k,l,m-1);
			case -1:return bsearch(a,k,m+1,h);
			case 0:return m;
		}
	}
	else
		return -1;
}
void main()
{
	int a[100],h,n,pos,i,k;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter key element\n");
	scanf("%d",&k);
	pos=bsearch(a,k,0,n-1);
	if(pos!=-1)
		printf("Key found at position %d\n",pos+1);
	else
		printf("Search unsuccessful\n");
}