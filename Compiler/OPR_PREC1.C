// OPERATOR PRECEDENCE PARSER FOR THE FOLLOWING GRAMMAR
//   		E->E+E|E-E|E*E|E/E|(E)|-E|id
//______________________________________________________
#include<stdio.h>
#include<conio.h>
#include<string.h>

int prec[9][9]={{1,1,-1,-1,-1,-1,1,1},
		{1,1,-1,-1,-1,-1,1,1},
		{1,1,1,1,-1,-1,1,1},
		{1,1,1,1,-1,-1,1,1},
		{1,1,1,1,10,10,1,1},
		{-1,-1,-1,-1,-1,-1,0,10},
		{1,1,1,1,10,10,1,1},
		{-1,-1,-1,-1,-1,-1,10,10}};
char str[20],stack[20];
int top,ip;
int e;
int getval(char x)
{
	switch(x)
	{
		case '+':	return(0);
		case '-':	return(1);
		case '*':	return(2);
		case '/':	return(3);
		case '(':	return(5);
		case ')':	return(6);
		case '$':	return(7);
		default:	return(4);
	}
}
int precedence()
{
	int p,q,r;
	p=getval(stack[top]);
	q=getval(str[ip]);
	r=prec[p][q];
	return(r);
}
int parse()
{
	loop:
	if(stack[top]=='$' && str[ip]=='$')
	{
		e=1;
		return(e);
	}
	else if(precedence()==-1 || precedence()==0)
	{
		top++;
		stack[top]=str[ip];
		ip++;
		printf("\n push %c",stack[top]);
	}
	else if(precedence()==1)
	{
		top=top-1; printf("\n pop %c",stack[top+1]);
		while(prec[getval(stack[top])][getval(stack[top+1])]!=-1)
		{
			top--;
			printf("\n pop %c",stack[top+1]);
		}
		printf("\n noop");
	}
	else
	{
		e=0;
		return(e);
	}
	goto loop;
}
int main()
{
	int s;

	printf("Enter the input string :");
	scanf("%s",str);
	stack[0]='$';
	str[strlen(str)]='$';
	s=parse();
	if(s==1)
		printf("\nAccepted");
	else
		printf("\nRejected");
	getch();
}
