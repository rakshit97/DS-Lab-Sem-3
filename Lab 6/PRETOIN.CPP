#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int top=-1;
char s[20][20];

void push(char *c)
{
  strcpy(s[++top],c);
}
char* pop()
{
  return s[top--];
}

void main()
{
  char a[20],b[20],c;
  int i,j,flag=0;
  clrscr();

  cout<<"Enter expression: ";
  gets(a);
  int l=strlen(a);
  strrev(a);		//reverse input, else is same
  int count=0;
  for(i=0;i<l;i++)
  {
    if((a[i]>=48 && a[i]<=57) || (a[i]>=97 && a[i]<=122) || (a[i]>=65 && a[i]<=90))
    {
      b[0]=a[i];
      b[1]='\0';
      push(b);
      count++;
    }
    else if(a[i]==42 || a[i]==43 || a[i]==45 || a[i]==47 || a[i]==94)
    {
      b[0]='\0';
      b[0]='(';
      b[1]='\0';
      char op2[20],op1[20];
      strcpy(op1,pop());	//swap op1 and op2
      strcpy(op2,pop());
      int l1=strlen(op1);
      int l2=strlen(op2);
      strcat(b,op1);
      b[l1+1]=a[i];
      b[l1+2]='\0';
      strcat(b,op2);
      b[l1+l2+2]=')';
      b[l1+l2+3]='\0';
      push(b);
    }

    else
    {
      cout<<"\nInvalid character!!!";
      break;
    }
  }

  while(top>=0)
    puts(pop());
  getch();
}