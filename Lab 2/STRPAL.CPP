#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
  clrscr();
  char a[50],b[50];
  int i,flag=0,l;
  cout<<"\nEnter the string: ";
  gets(a);
  for(i=0;a[i]!='\0';i++);
  l=i;
  for(i=0;i<l;i++)
  {
    if(a[i]!=a[l-i-1])
    {
      flag=1;
      cout<<"\nNot a palindrome";
      break;
    }
  }
  if(flag==0)
    cout<<"It is a palindrome";

  getch();
}
