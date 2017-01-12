#include<iostream.h>
#include<conio.h>
#include<process.h>

int front=0, rear=0,size;
int a[10];

void insert(int x)
{
  if((rear+1)%size==front)
    cout<<"Queue overflow!!!";
  else
  {
    a[(++rear)%size]=x;
    cout<<"\nElement inserted";
  }
}
int del()
{
  if(front==rear)
    cout<<"Queue empty!!!";
  else
    return a[(++front)%size];
  return -1;
}
void display()
{
  for(int i=(front+1)%size;i!=(rear+1)%size;i=(i+1)%size)
    cout<<a[i]<<" ";
}

void main()
{
  clrscr();
  int choice;
  cout<<"Enter size of queue: ";
  cin>>size;
  char cont='y';

  while(cont=='y')
  {
    cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"\nEnter element to be inserted: ";
	      int x;
	      cin>>x;
	      insert(x);
	      break;
      case 2: cout<<"Deleted element: "<<del();
	      break;
      case 3: display();
	      break;
      case 4: exit(0);
    }
    cout<<"\nDo you want to continue(y/n): ";
    cin>>cont;
    if(cont=='n')
      exit(0);
  }
}