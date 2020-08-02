#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int failure[100];
void fail(char *p)
{
	int n=strlen(p),i,j;
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		while(p[j]!=p[i+1]&&i>=0)
			i=failure[i];
		if(p[j]==p[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
}
int pmatch(char *s,char *p)
{
	int ls=strlen(s);
	int lp=strlen(p),i=0,j=0;
	while(i<ls&&j<lp)
	{
		if(s[i]==p[j])
		{
			i++;j++;
		}
		else if(j==0)
		{
			i++;
		}
		else
			j=failure[j-1]+1;
	}
	return ((j==lp)?i-lp:-1);
}
void main()
{
	char s[100],p[100],k;
	printf("Enter string\n");
	scanf("%s",s);
	printf("Enter pettern\n");
	scanf("%s",p);
	fail(p);
	k=pmatch(s,p);
	if(k==-1)
		printf("Pattern not found\n");
	else
		printf("Pattern found at position %d\n",k+1);
}
