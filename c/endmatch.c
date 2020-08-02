#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int endmatch(char *s,char *p)
{
	int ls=strlen(s)-1;
	int lp=strlen(p)-1,i=0,j=0,start=0,em=lp;
	for(i=0;em<=ls;em++,start++)
	{
		if(s[em]==p[lp])
			for(j=0,i=start;s[i]==p[j]&&j<lp;i++,j++);
		if(j==lp)
			return start;
	}
	return -1;
}
void main()
{
	char s[100],p[100],k;
	printf("Enter string\n");
	scanf("%s",s);
	printf("Enter pattern\n");
	scanf("%s",p);
	k=endmatch(s,p);
	if(k==-1)
		printf("Pattern not found\n");
	else
		printf("Pattern found at position %d\n",k+1);
}
