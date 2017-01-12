#include<iostream.h>
#include<conio.h>
#include<process.h>

class dll
{
  int data;
  dll *left;
  dll *right;

  public:
  void insert();
  void ins_before();
  void ins_after();
  void del();
  void traverse();
  void reverse();
};

dll *front=NULL;
dll *rear=NULL;

void dll::insert()
{
  cout<<"\nEnter data: ";
  dll *temp = new dll;
  cin>>temp->data;
  temp->right=NULL;
  temp->left=rear;

  if(front==NULL)
    front=temp;
  else
    rear->right=temp;
  rear=temp;
  cout<<"\nElement inserted!";
}

void dll::ins_before()
{
  cout<<"\nEnter data: ";
  dll *temp=new dll;
  cin>>temp->data;
  cout<<"\nInsert before: ";
  int key;
  cin>>key;

  if(front->data==key)
  {
    temp->left=NULL;
    temp->right=front;
    front->left=temp;
    front=temp;
  }
  else
  {
    for(dll *curr=front;curr!=NULL;curr=curr->right)
    {
      if(curr->data==key)
      {
	temp->left=curr->left;
	temp->right=curr;
	curr->left->right=temp;
	curr->left=temp;
      }
    }
  }
  cout<<"\nElement inserted!";
}

void dll::ins_after()
{
  cout<<"\nEnter data: ";
  dll *temp=new dll;
  cin>>temp->data;
  cout<<"\nInsert after: ";
  int key;
  cin>>key;

  for(dll *curr=front;curr!=NULL;curr=curr->right)
  {
    if(curr->data==key)
    {
      temp->left=curr;
      temp->right=curr->right;
      curr->right->left=temp;
      curr->right=temp;
    }
  }
  cout<<"\nElement inserted!";
}

void dll::del()
{
  cout<<"\nElement to be deleted: ";
  int key;
  cin>>key;
  if(front->data==key)
  {
    front->right->left=NULL;
    dll *temp=front;
    front=front->right;
    delete temp;
  }
  if(rear->data==key)
  {
    dll *temp=rear;
    rear->left->right=NULL;
    rear=rear->left;
    delete temp;
  }
  else
  {
    for(dll *curr=front;curr!=rear;curr=curr->right)
    {
      if(curr->data==key)
      {
	dll *temp=curr;
	curr->left->right=curr->right;
	curr->right->left=curr->left;
	delete temp;
      }
    }
  }
  cout<<"\nElement deleted!";
}

void dll::traverse()
{
  cout<<"\n";
  for(dll *curr=front;curr!=NULL;curr=curr->right)
    cout<<curr->data<<" -> ";
}

void dll::reverse()
{
  cout<<"\n";
  for(dll *curr=rear;curr!=NULL;curr=curr->left)
    cout<<curr->data<<" -> ";
}

void main()
{
  clrscr();
  dll l;
  int opt;
  char cont='y';

  while(cont=='y' || cont=='Y')
  {
    cout<<"\n1. Insert"
	<<"\n2. Insert Before"
	<<"\n3. Insert After"
	<<"\n4. Delete"
	<<"\n5. Traverse"
	<<"\n6. Reverse"
	<<"\n7. Exit"
	<<"\n\nYour choice: ";
    cin>>opt;

    switch(opt)
    {
      case 1: l.insert(); break;
      case 2: l.ins_before(); break;
      case 3: l.ins_after(); break;
      case 4: l.del(); break;
      case 5: l.traverse(); break;
      case 6: l.reverse(); break;
      case 7: exit(0);
    }

    cout<<"\n\nContinue?(y/n): ";
    cin>>cont;
  }
  getch();
}