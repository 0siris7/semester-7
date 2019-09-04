#include<stdio.h>
#include<conio.h>
#include<string.h>

int t1=-1,t2=-1,i,k=0;
char s[50],p[50];

void push1(char a)
 { if(t1<=49)
     {
	 	t1++;
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
 
 void printpost()
  {int j=0;
    
    while(j<=t2)
     { 
         if(p[j]!='(')       
           {printf("%c",p[j]);
           }        
           j++;
      }
  }
    
    
    int main()
     {
         char a[50],c,d='t';
         
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
         	k=1;
 			printf("\n\nThe postfix expression is:");
 			printf("%s",p);
 			printf("\n\nOP\tOP1\tOP2\tResult");
 			for(i=0;i<strlen(p);i++)
 			{
 				if(isalpha(p[i]))
 				{
 					push1(p[i]);
				}
				else
				{
					printf("\n%c",p[i]);
					c=pop();
					if(c=='t')
					{
						printf("\t%c%d",d,k-1);
					}
					else	
					{
						printf("\t%c",c);
					}						
					c=pop();
					if(c=='t')
					{
						printf("\t%c%d",d,k-1);
					}
					else	
					{
						printf("\t%c",c);
					}
					printf("\t%c%d",d,k);
					k++;
					push1(d);
				}
 			}
 //printpost();
			
			 getch();
 			return 0;
   }

    
    
    
    
    
    
    
    
    
