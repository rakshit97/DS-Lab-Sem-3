#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

char a[50];
int top=-1;
void push(char x)
{
  a[++top]=x;
}
char pop()
{
  return a[top--];
}

void main()
{
  clrscr();
  char exp[50];
  int l=0, flag=0;
  cout<<"Enter the expression: ";
  gets(exp);
  l=strlen(exp);
  for(int i=0;i<l;i++)
  {
    char x=exp[i];
    if(x=='[' || x=='{' || x=='(')
      push(x);
    if(x==']' || x=='}' || x==')')
    {
      if(x==']' && pop()!='[')
	flag=1;
      if(x=='}' && pop()!='{')
	flag=1;
      if(x==')' && pop()!='(')
	flag=1;
    }
    if(flag==1)
    {
      cout<<"\nExpression not balanced!!!";
      break;
    }
  }
  if(flag==0)
    cout<<"\nBalanced expression";
  getch();
}

