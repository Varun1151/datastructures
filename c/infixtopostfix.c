#include<stdio.h>
typedef enum{
	lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
int sp[]={0,19,14,14,17,17,17,0};
int icp[]={20,19,14,14,17,17,17,0};
precedence stack[100];
int top=0;
char expr[100];
precedence gettoken(char*,int*);
void printtoken(precedence);
void push(precedence);
precedence pop();
void postfix()
{
	precedence token;
	char symbol;
	int n=0;
	stack[0]=eos;
	for(token=gettoken(&symbol,&n);token!=eos;token=gettoken(&symbol,&n))
	{
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
			   printtoken(pop());
		    pop();
		}
		else
		{
			while(sp[stack[top]]>=icp[token])
				printtoken(pop());
			push(token);
		}
	}
		while(stack[top]!=eos)
			printtoken(pop());
		printf("\n");
}
void main()
{
	printf("Enter a infix expression\n");
	scanf("%s",expr);
	postfix();
}
void push(precedence token)
{
	stack[++top]=token;
}
precedence pop()
{
	return stack[top--];
}
void printtoken(precedence token)
{
	switch(token)
	{
		case plus:printf("+");
		          break;
		case minus:printf("-");
		          break;
		case times:printf("*");
		          break;
		case divide:printf("/");
		          break;
		case mod:printf("%%");
		          break;
	}
}
precedence gettoken(char *s,int *n)
{
	*s=expr[(*n)++];
	switch(*s)
	{
		case '(':return lparen;
		case ')':return rparen;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		case '\0':return eos;
		default:return operand;
	}
}

		     