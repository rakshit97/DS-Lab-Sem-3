#include<iostream.h>
#include<conio.h>
#include<process.h>

class list
{
  int data;
  list *next;

  public:
  void push();
  void pop();
  void insert();
  void del();
  void disp();
};

list *bottom=NULL;
list *top=NULL;
list *front=NULL;
list *rear=NULL;

void list::push()
{
  int x;
  cout<<"\nEnter data: ";
  cin>>x;
  list *temp=new list;
  temp->data=x;
  temp->next=NULL;
  if(bottom==NULL)
  {
    bottom=temp;
    top=temp;
  }
  else
  {
    top->next=temp;
    top=temp;
  }
}

void list::pop()
{
  if(bottom==NULL)
    cout<<"\nStack empty!!!";
  else if(bottom->next==NULL)
  {
    cout<<"\nElement popped: "<<bottom->data;
    bottom=NULL;
  }
  else
  {
    list *curr;
    int k;
    for(k=0,curr=bottom;curr!=top;curr=curr->next,k++)
    {
      if(k==3)
	break;
      list *curr1=curr->next;
      if(curr1==top)
      {
	curr->next=NULL;
	top=curr;
	cout<<"\nElement popped: "<<curr1->data;
	delete curr1;
	break;
      }
    }
  }
}

void list::insert()
{
  int x;
  cout<<"\nEnter data: ";
  cin>>x;
  list *temp=new list;
  temp->data=x;
  temp->next=NULL;
  if(front==NULL)
  {
    front=temp;
    rear=temp;
  }
  else
  {
    rear->next=temp;
    rear=temp;
  }
}

void list::del()
{
  if(front==NULL)
    cout<<"\nQueue empty!!!";
  else
  {
    cout<<"\nElement deleted: "<<front->data;
    list* temp=front;
    front=front->next;
    delete temp;
  }
}

void list::disp()
{
  cout<<"\n1.Display stack\n2.Display queue\n\nYour choice: ";
  int opt;
  cin>>opt;
  if(opt==1)
    for(list *curr=bottom;curr!=NULL;curr=curr->next)
      cout<<curr->data<<" -> ";
  else if(opt==2)
    for(list *curr=front;curr!=NULL;curr=curr->next)
      cout<<curr->data<<" -> ";
  else
    cout<<"\nEnter valid option!!!";
}

void main()
{
  clrscr();
  int opt;
  char cont='y';
  list l;

  while(cont=='y')
  {
    cout<<"\n1.Push\n2.Pop\n3.Insert\n4.Delete\n5.Display\n\nEnter your choice: ";
    cin>>opt;
    if(opt==1)
      l.push();
    if(opt==2)
      l.pop();
    if(opt==3)
      l.insert();
    if(opt==4)
      l.del();
    if(opt==5)
      l.disp();
    cout<<"\nContinue(y/n): ";
    cin>>cont;
  }
}
