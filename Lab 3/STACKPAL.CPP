#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int top=-1;
char s[50];

char pop()
{
  return s[top--];
}
void push(char c)
{
  s[++top]=c;
}

void main()
{
  clrscr();
  char str[50];
  int i,l,count=0;
  cout<<"Enter the string: ";
  gets(str);
  l=strlen(str);
  for(i=0;i<l;i++)
    push(str[i]);
  for(i=0;i<l;i++)
    if(str[i]==pop())
      count++;

  if(count==l)
    cout<<"\nIt is a palindrome.";
  else
    cout<<"\nNot a palindrome.";
  getch();
}