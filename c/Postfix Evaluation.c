//Postfix evaluation
#include<stdio.h>
#include<stdlib.h>
void push(int);
int pop();
char expr[100];
int stack[100],top=-1;
typedef enum{
lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

precedence gettoken(char *s,int *n);
int eval()
{
	precedence token;
	char symbol;
	int op1,op2,n=0;
	token=gettoken(&symbol,&n);
	while(token!=eos)
	{
		if(token==operand)
			push(symbol-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
				case plus:
				     push(op1+op2);
					 break;
				case minus:
				     push(op1-op2);
					 break;
				case times:
				     push(op1*op2);
					 break;
				case divide:
				     push(op1/op2);
					 break;
				case mod:
				     push(op1%op2);
					 break;
			}
		}
		token=gettoken(&symbol,&n);
	}
	return pop();
}

precedence gettoken(char *s,int *n)
{
	*s=expr[(*n)++];
	switch(*s)
	{
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		case '\0':return eos;
		default:return operand;
	}
}

void main()
{
	int res;
	printf("Enter the postfix expression\n");
	scanf("%s",expr);
	res=eval();
	printf("Result is %d\n",res);
}

void push(int x)
{
	stack[++top]=x;
}

int pop()
{
	return stack[top--];
}