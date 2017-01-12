#include<iostream.h>
#include<conio.h>
#include<process.h>

class dll
{
  int data;
  dll *left;
  dll *right;

  public:
  void ins();
  void concat();
  void disp();
};

dll *front1=NULL;
dll *rear1=NULL;
dll *front2=NULL;
dll *rear2=NULL;

void dll::ins()
{
  int n,x;
  cout<<"\nInsert in list 1 or 2? ";
  cin>>n;
  dll *temp=new dll;
  cout<<"\nEnter data: ";
  cin>>x;
  temp->data=x;
  temp->right=NULL;
  if(n==1)
  {
    if(front1==NULL)
    {
      front1=temp;
      rear1=temp;
      temp->left=front1;
    }
    else
    {
      rear1->right=temp;
      temp->left=rear1;
      rear1=temp;
    }
  }
  else if(n==2)
  {
    if(front2==NULL)
    {
      front2=temp;
      rear2=temp;
      temp->left=front2;
    }
    else
    {
      rear2->right=temp;
      temp->left=rear2;
      rear2=temp;
    }
  }
  else
    cout<<"\nEnter valid list number!!!";
}

void dll::disp()
{
  int n;
  cout<<"\nDisplay list 1 or 2? ";
  cin>>n;
  if(n==1)
    for(dll *curr=front1;curr!=NULL;curr=curr->right)
      cout<<curr->data<<" -> ";
  else if(n==2)   \
    for(dll *curr=front2;curr!=NULL;curr=curr->right)
      cout<<curr->data<<" -> ";
  else
    cout<<"\nEnter valid list number!!!";
}

void dll::concat()
{
  rear1->right=front2;
  front2->left=rear1;
  for(dll *curr=front1;curr!=NULL;curr=curr->right)
    cout<<curr->data<<" -> ";
}

void main()
{
  clrscr();
  char cont='y';
  int opt;
  dll l;

  while(cont=='y')
  {
    cout<<"\n1.Insert\n2.Display\n3.Concatenate\n4.Exit\n\nEnter your choice: ";
    cin>>opt;
    switch(opt)
    {
      case 1:  l.ins();
	       break;
      case 2:  l.disp();
	       break;
      case 3:  l.concat();
	       break;
      case 4: exit(0);
    }
    cout<<"Continue(y/n): ";
    cin>>cont;
  }
}