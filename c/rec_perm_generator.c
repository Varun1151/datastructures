#include<stdio.h>
#include<string.h>
#define SWAP(a,b,c) c=a,a=b,b=c
void perm(char *list,int i,int n)
{
  int j;
  char temp;
  if(i==n)
  {
	  for(j=0;j<=n;j++)
		  printf("%c",list[j]);
	  printf(" ");
  }
  else 
  {
	  for(j=i;j<=n;j++)
	  {
		  SWAP(list[i],list[j],temp);
		  perm(list,i+1,n);
		  SWAP(list[i],list[j],temp);
	  }
  }
}
void main()
{
	char list[100];
	int n;
	printf("Enter word\n");
	scanf("%s",list);
	n=strlen(list);
	perm(list,0,n-1);
}