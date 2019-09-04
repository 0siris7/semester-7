#include<stdio.h>
#include<conio.h>

int flag=0;

int e_(char str[],int i)
{
	if(str[i]=='+')
	{
		i++;
		
		i=t(str,i);
		i=e_(str,i);
	}
	return i;
}
int t_(char str[],int i)
{
	if(str[i]=='*')
	{
		i++;
		
		i=f(str,i);
		i=t_(str,i);
	}

	return i;
}


int f(char str[],int i)
{
	if (str[i]=='(')
	{
		i++;
		i=e(str,i);
		
		if (str[i]==')')
		{
			i++;
			
			return i;
		}
	}
	else if(isalpha(str[i]))
	{
		i++;
		
		return i;
	}
	else
	{
		flag=1;
		
		return i;
	}
}

int t(char str[],int i)
{
	i=f(str,i);
	i=t_(str,i);
	
	return i;
}
int e(char str[],int i)
{

	i=t(str,i);
	i=e_(str,i);
	
	return i;
} 



int main()
{
	int i=0;
	char str[100];
	printf("Enter the string:");
	scanf("%s",&str);
	
	i=e(str,i);
	
	if( str[i]=='\0'&&flag==0)
	{
		printf("Accepted!");
	}
	else
	{
		printf("Rejected!");
	}
	getch();
}
