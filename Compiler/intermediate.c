#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
//---------------------------Infix to postfix---------------
int t1=-1,t2=-1,i,k=0;
char s[50],p[50];

void push1(char a)
 { if(t1<=49)
     {t1++;
     s[t1]=a;
             
     }
 }
  
  void push2(char a)
 { if(t2<=49)
     {t2++;
     p[t2]=a;
     }
 }
 
 
 char pop()
 { 
      char b;
      if(t1!=-1)
       {b=s[t1];
        t1--;
       }
        return b;     
 }
 
 /*void printpost()
  {int j=0;
    
    while(j<=t2)
     { 
         if(p[j]!='(')       
           {printf("%c",p[j]);
           }        
           j++;
      }
  }*/
    
    
    int main()
     {
         char a[50],c;
         
         printf("Enter the expression:");
         scanf("%s",a);
         
         for(i=0;a[i]!='\0';i++)
           {
                if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
                   {
                        push2(a[i]);                                        
                                                                  
                   }               
                else if(a[i]=='(')
                    {
                        push1(a[i]);         
                                  
                    }
                    
                else if(a[i]==')')
                   { while(s[t1]!='(')
                       {
                          c=pop();
                          push2(c);            
                                      
                       }
                                  
                   }
                   
                else
                  {
                     switch(a[i])
                       {
                         case '+':
                                    while(k==0)
                                      { if(s[t1]=='+'||s[t1]=='-'||s[t1]=='*'||s[t1]=='/'||s[t1]=='^')
                                            { c=pop();
                                               push2(c);
                                                                                                      
                                              }
                                         else 
                                           {
                                           push1(a[i]);
                                           k=1;                                                           
                                           }
                                             
                                      }
                                      k=0;
                                      break;
                                      
                         case '-':
                                    while(k==0)
                                      { if(s[t1]=='+'||s[t1]=='-'||s[t1]=='*'||s[t1]=='/'||s[t1]=='^')
                                            { c=pop();
                                               push2(c);
                                            }
                                         else 
                                           {
                                           push1(a[i]);
                                           k=1;                                                           
                                           }
                                             
                                      }
                                      k=0;
                                      break;
                                      
                         case '*':
                                    while(k==0)
                                      { if(s[t1]=='*'||s[t1]=='/'||s[t1]=='^')
                                            { c=pop();
                                               push2(c);
                                            }
                                         else 
                                           {
                                           push1(a[i]);
                                           k=1;                                                           
                                           }
                                             
                                      }
                                      k=0;
                                      break;
                                      
                                      
                         case '/':
                                    while(k==0)
                                      { if(s[t1]=='*'||s[t1]=='/'||s[t1]=='^')
                                            { c=pop();
                                               push2(c);
                                            }
                                         else 
                                           {
                                           push1(a[i]);
                                           k=1;                                                           
                                           }
                                      }
                                      k=0;
                                      break;
                                      
                         case '^':
                                    while(k==0)
                                      { if(s[t1]=='^')
                                            { c=pop();
                                               push2(c);
                                            }
                                         else 
                                           {
                                           push1(a[i]);
                                           k=1;                                                           
                                           }
                                        
                                      }
                                      k=0;
                                      break;
                                      
                       }
                                  
                                  
                  }
                
                
           }
                               
           while(t1!=-1)
             {
                c=pop();
                push2(c);
                        
             }
         
 printf("\n\nThe postfix expression is:");
  printf("%s", p);
 
 //Pushing to stack and performing the format
 struct exp
{
	char op, op1,op2,result;
	int numb;
	
}ex[10];
     
int stack[10];     
int top = -1;            
char element;
//POP infix stuff from  stack
char pop_infix() {
	char data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("\nCould not retrieve data, Stack is empty.\n");
   }
}

void push_infix(char data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("\nCould not insert data, Stack is full.\n");
   }
}


int total = 0
for(i = 0; p[i] != '\0'; ++i)
	{	
		if(isalpha(p[i]))
			{
				push_infix(p[i]);
			}
			
		else
			{	ex[i].op = p[i];
				ex[i].op1 = pop_infix();
				ex[i].op2 = pop_infix();
				ex[i].result = "t"
				ex[i].numb = i + 1
				push_infix("t");
				total += 1
				
			}
	}
 printf("\n\nOP\tOP1\tOP2\tResult");
 for(i = 0;i<total; i++)
		{
			//printf("\n%c%c%c%c\n",ex[i].op,ex[i].op1,ex[i].op2,ex[i].result);
			printf("\n%c"ex[i].op)
			
		}
 

 getch();
 return 0;
         
 }
    
    
    
    
    
    
    
    
    
    
