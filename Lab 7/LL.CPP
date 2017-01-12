#include<iostream.h>
#include<conio.h>
#include<process.h>

class list
{
  int data;
  list* next;

  public:
  void insert();
  void insert_before();
  void insert_after();
  void del();
  void traverse();
  void reverse();
  void sort();
  void del_alt();
  void insert_sorted();
  void getsize();
};

list *front=NULL;
list *rear=NULL;
int l=0;

void list::getsize()
{
  int i;list *curr;
  for(i=0,curr=front;curr->next!=NULL;curr=curr->next,i++);
  l=i;
}

void list::insert()
{
  list *tmp =new list;
  cout<<"\nEnter data: ";
  cin>>tmp->data;
  if(front==NULL)
  {
    front=tmp;
    rear=tmp;
    tmp->next=NULL;
  }
  else
  {
    rear->next=tmp;
    tmp->next=NULL;
    rear=tmp;
  }
}

void list::insert_before()
{
  list *tmp =new list;
  cout<<"\nEnter data: ";
  cin>>tmp->data;
  cout<<"Enter element before which you want to store data: ";
  int key;
  cin>>key;
  for(list *curr=front;curr->next!=NULL;curr=curr->next)
  {
    list *curr1;
    curr1=curr->next;
    if(curr1->data==key)
    {
      curr->next=tmp;
      tmp->next=curr1;
    }
  }
}

void list::insert_after()
{
  list *tmp =new list;
  cout<<"\nEnter data: ";
  cin>>tmp->data;
  cout<<"Enter element after which you want to store data: ";
  int key;
  cin>>key;
  for(list *curr=front;curr!=NULL;curr=curr->next)
  {
    list *curr1;
    curr1=curr->next;
    if(curr->data==key)
    {
      curr->next=tmp;
      tmp->next=curr1;
    }
  }
}

void list::del()
{
  cout<<"Enter element you want to delete: ";
  int key;
  cin>>key;
  for(list *curr=front;curr!=NULL;curr=curr->next)
  {
    list *curr1;
    curr1=curr->next;
    if(curr1->data==key)
    {
      curr->next=curr1->next;
      delete curr1;
    }
  }
}

void list::traverse()
{
  for(list *curr=front;curr!=NULL;curr=curr->next)
  {
    cout<<curr->data<<" -> ";
  }
}

void list::reverse()
{
  int arr_data[50],l=0,i=0;
  list *curr;
  for(curr=front,i=0;curr!=NULL;curr=curr->next,i++)
  {
    arr_data[i]=curr->data;
  }
  getsize();
  for(i=l-1;l>=0;l--)
    cout<<arr_data[i]<<" -> ";
}

void list::sort()
{
  int j;
  getsize();
  for(int i=0;i<l;i++)
  {
    j=0;
    for(list* curr=front;j<l-i;j++,curr=curr->next)
    {
      list *prev=curr;
      curr=curr->next;
      list *curr1=curr->next;
      if(curr->data>curr1->data)
      {
	prev->next=curr1;
	curr->next=curr1->next;
	curr1->next=curr;
      }
    }
  }
}

void list::del_alt()
{
  for(list *curr=front;curr!=NULL;curr=curr->next)
  {
    list *curr1=curr->next;
    curr->next=curr1->next;
    delete curr1;
  }
}

void list::insert_sorted()
{
  list *tmp =new list;
  cout<<"\nEnter data: ";
  cin>>tmp->data;
  for(list *curr=front;curr!=NULL;curr=curr->next)
  {
    if(tmp->data>curr->data && tmp->data<curr->next->data)
    {
      tmp->next=curr->next;
      curr->next=tmp;
    }
  }
}

void main()
{
  clrscr();
  list l;
  int opt;
  abc:
  cout<<"\n1.Insert element."
      <<"\n2.Insert an element after another element."
      <<"\n3.Insert an element before another element."
      <<"\n4.Delete an element."
      <<"\n5.Traverse"
      <<"\n6.Reverse"
      <<"\n7.Sort"
      <<"\n8.Delete alternate elements."
      <<"\n9.Insert an element in sorted list."
      <<"\n10.EXIT\n";
  cin>>opt;
  switch(opt)
  {
    case 1: l.insert();break;
    case 2: l.insert_before();break;
    case 3: l.insert_after();break;
    case 4: l.del();break;
    case 5: l.traverse();break;
    case 6: l.reverse();break;
    case 7: l.sort();break;
    case 8: l.del_alt();break;
    case 9: l.insert_sorted();break;
    case 10: exit(0);
    default: cout<<"\nEnter valid option!";goto abc;
  }
  goto abc;
  getch();
}