#include <stdio.h>
#include <conio.h>
int A(char a[], int i)
{
	
			if(a[i] == 'a' && a[i + 1] == 'b')
				{
					i = i + 2;
				}
						
			else if(a[i] == 'a')
				{
					i = i + 1;
				}
				
			else
				{
					return 0;
				}
		
			if(a[i] == 'd' && a[i + 1] == '\0')
				{
					return 1;
				}
				
			else
				{
					return 0;
				}
}
void S(char str[])
{	int flag = 0;
	if (str[0] == 'a')
		{	int i = 1;
			flag = A(str, i);
		}
		
	if(flag == 1)
		{
			printf("parsing sucessfull");
		}
	
	else
	 {
	 	printf("Error");
	 }
	
}
int main()
{
	char ip[100];
	printf("Enter your string:");
	scanf("%s", ip);
	S(ip);
	
		
}
