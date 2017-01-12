#include<iostream.h>
#include<conio.h>

int a[50],top=-1;
void push(int rem)
{
  a[++top]=rem;
}

int pop()
{
  return a[top--];
}

void main()
{
  clrscr();
  int num, i, base;

  cout<<"Enter your decimal number: ";
  cin>>num;
  cout<<"\nEnter the base to which you want to convert it(2/8/16): ";
  cin>>base;

  if(base==2 || base==8 || base==16)
  {
    while(num>0)
    {
      push(num%base);
      num/=base;
    }
  }
  else
    cout<<"\nInvalid base entered!!!";

  while(top>=0)
  {
    int x=pop();
    if(x==10)
      cout<<"A";
    else if(x==11)
      cout<<"B";
    else if(x==12)
      cout<<"C";
    else if(x==13)
      cout<<"D";
    else if(x==14)
      cout<<"E";
    else if(x==15)
      cout<<"F";
    else
      cout<<x;
  }
  getch();
}