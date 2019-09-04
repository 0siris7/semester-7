#include<stdio.h>
#include<conio.h>

struct exp
{
	char op, op1,op2,result;
	
}ex[10];

int main()
{
	char string[100],val,var;
	int tot, i, j = 0;
	printf("Enter number of statements");
	scanf("%d", &tot);
	for(i = 0;i<tot;i++)
		{	printf("Enter string %d:", i);
			scanf("%s", string);
			ex[i].op = string[0];
			ex[i].op1 = string[1];
			ex[i].op2 = string[2];
			ex[i].result = string[3];
			if(ex[i].op == '=')
				{
					val = ex[i].op1;
					var = ex[i].result;
				}
		}
	

	for(i = 1; i < tot; i++)
		{
			if(ex[i].op1 == var)
				{
					ex[i].op1 = val;
				}
			
			if(ex[i].op2 == var)
				{
					ex[i].op2 = val;
				}
				
		}
		
	for(i = 1;i<tot; i++)
		{
			printf("%c%c%c%c\n",ex[i].op,ex[i].op1,ex[i].op2,ex[i].result);
		}
	
}
