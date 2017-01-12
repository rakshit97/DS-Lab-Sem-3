#include<iostream.h>
#include<conio.h>
#include<process.h>

int a[200],top[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
void push(int x, int num)
{
  if(top[num-1]==20)
    cout<<"\nStack Overflow!!!";
  else
    a[++top[num-1]+((num-1)*20)+1]=x;
}
int pop(int num)
{
  if(top[num-1]==-1)
  {
    cout<<"\nNothing to pop!!!";
    return -1;
  }
  else
    return a[((num-1)*20)+1+top[num-1]--];
}
void display(int num)
{
  for(int i=((num-1)*20)+top[num-1]+1;i>(num-1)*20;i--)
    cout<<a[i]<<"\n";
}

void main()
{
  clrscr();
  int num, x, choice;
  cout<<"You can have max 10 stacks!!!";
  abc:
  cout<<"\n\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n\nYour choice: ";
  cin>>choice;
  if(choice==1)
  {
    cout<<"\nEnter element: ";
    cin>>x;
    cout<<"\nEnter stack no.(max 10): ";
    cin>>num;
    push(x,num);
    cout<<"\nElement pushed!";
  }
  else if(choice==2)
  {
    cout<<"\nEnter stack no.(max 10): ";
    cin>>num;
    x=pop(num);
    if(x!=-1)
      cout<<"\nElement popped: "<<x;
  }
  else if(choice==3)
  {
    cout<<"\nEnter stack no.(max 10): ";
    cin>>num;
    display(num);
  }
  else if(choice==4)
    exit(0);
  else
    cout<<"\nEnter valid choice!!!";
  goto abc;
  getch();
}