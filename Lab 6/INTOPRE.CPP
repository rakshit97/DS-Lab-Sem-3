#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int top=-1;
char s[20];

void push(char c)
{
  s[++top]=c;
}
char pop()
{
  return s[top--];
}

void main()
{
  char a[20],b[20],c;
  int i,j;
  clrscr();

  cout<<"Enter expression: ";
  gets(a);
  int l=strlen(a);
  strrev(a);
  int count=0;
  for(i=0;i<l;i++)
  {
    if(a[i]>=48 && a[i]<=57 || (a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
    {
      b[count]=a[i];
      count++;
    }
    else if(a[i]==42 || a[i]==43 || a[i]==45 || a[i]==47 || a[i]==94)
    {
      if(top==-1)
      {
	push(a[i]);
	continue;
      }
      if(top>=0)
      {
	if(a[i]=='-')
	{
	  while(top!=-1)
	  {
	    b[count]=pop();
	    count++;
	  }
	  push(a[i]);
	}
	if(a[i]=='+')
	{
	  for(j=top;j>=0;j--)
	  {
	    if(s[top]=='/' || s[top]=='*' || s[top]=='+' || s[top]=='^')
	    {
	      b[count]=pop();
	      count++;
	    }
	    else
	      break;
	  }
	  push(a[i]);
	}
	if(a[i]=='/')
	{
	  for(j=top;j>=0;j--)
	  {
	    if(s[top]=='/' || s[top]=='*' || s[top]=='^')
	    {
	      b[count]=pop();
	      count++;
	    }
	    else
	      break;
	  }
	  push(a[i]);
	}
	if(a[i]=='*')
	{
	  for(j=top;j>=0;j--)
	  {
	    if(s[top]=='/' || s[top]=='*' || s[top]=='^')
	    {
	      b[count]=pop();
	      count++;
	    }
	    else
	      break;
	  }
	  push(a[i]);
	}
	if(a[i]=='^')
	{
	  for(j=top;j>=0;j--)
	  {
	    if(s[top]=='^')
	    {
	      b[count]=pop();
	      count++;
	    }
	    else
	      break;
	  }
	  push(a[i]);
	}
      }
    }
    else
      cout<<"\nInvalid expression!!!";
  }
  while(top!=-1)
  {
    b[count]=pop();
    count++;
  }
  b[count]='\0';
  strrev(b);
  puts(b);
  getch();
}