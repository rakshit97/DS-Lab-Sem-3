#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

class BT
{
  public:
  int data;
  BT *left;
  BT *right;

  void preorder();
  void inorder();
  void postorder();
  void parent(BT *node, int key);
  void ancestor(BT *node, int key, int stack[], int top);
  int leaf_count(BT *node, int count);
  void recur_print(BT *node);
  void insert(BT *node, char *pos, BT *to_ins, int i);
  int depth(BT *node);
};

BT *root=new BT;

void BT::insert(BT *node, char *pos, BT *to_ins, int i)
{
  if(strcmpi(pos,"root")==0)
  {
    if(root==NULL)
    {
      root=to_ins;
      cout<<"\nRoot created!";
      return;
    }
    else
    {
      cout<<"\nRoot already exists!";
      return;
    }
  }

  if(pos[i]=='l' || pos[i]=='L')
  {
    if(node->left==NULL && i==strlen(pos)-1)
    {
      node->left=to_ins;
      cout<<"\nElement inserted!";
      return;
    }
    else if(node->left!=NULL && i<strlen(pos)-1)
    {
      i++;
      insert(node->left, pos, to_ins,i);
    }
    else if(node->left==NULL && i<strlen(pos)-1)
    {
      cout<<"\nERROR!!! Cannot insert element!";
      return;
    }
    else if(node->left!=NULL && i==strlen(pos)-1)
    {
      cout<<"\nERROR!!! Cannot insert element!";
      return;
    }
  }
  else if(pos[i]=='r' || pos[i]=='R')
  {
    if(node->right==NULL && i==strlen(pos)-1)
    {
      node->right=to_ins;
      cout<<"\nElement inserted!";
      return;
    }
    else if(node->right!=NULL && i<strlen(pos)-1)
    {
      i++;
      insert(node->right, pos, to_ins,i);
    }
    else if(node->right==NULL && i<strlen(pos)-1)
    {
      cout<<"\nERROR!!! Cannot insert element!";
      return;
    }
    else if(node->right!=NULL && i==strlen(pos)-1)
    {
      cout<<"\nERROR!!! Cannot insert element!";
      return;
    }
  }
  else
    cout<<"\nEnter valid path!!!";
}

void BT::recur_print(BT *node)
{
  if(node==NULL)
    return;
  cout<<node->data<<" ";
  recur_print(node->left);
  recur_print(node->right);
}

void BT::preorder()
{
  int top=-1;
  BT *stack[100];

  BT *ptr=root;
  while(1)
  {
    cout<<ptr->data<<" ";
    if(top==-1 && ptr->left==NULL && ptr->right==NULL)
      break;
    if(ptr->right!=NULL)
      stack[++top]=ptr;
    ptr=ptr->left;
    if(ptr==NULL)
    {
      ptr=stack[top--];
      ptr=ptr->right;
    }
  }
}

void BT::inorder()
{
  int top=-1;
  BT *stack[100];
  BT *ptr=root;

  do
  {
    for(;ptr;ptr=ptr->left)
    stack[++top]=ptr;

    if(top>=0)
      ptr=stack[top--];
    else
      break;

    cout<<ptr->data<" ";
    ptr=ptr->right;

  }while(1);
}

/*void BT::inorder()
{
  int top=-1;
  BT *stack[100];

  BT *ptr=root;
  while(1)
  {
    if(ptr->left==NULL)
    {
      cout<<ptr->data<<" ";
      if(top==-1 && ptr->left==NULL && ptr->right==NULL)
	break;
      abc:
      ptr=stack[top--];
      cout<<ptr->data<<" ";
      ptr=ptr->right;
      if(ptr==NULL)
	goto abc;
    }
    stack[++top]=ptr;
    ptr=ptr->left;
  }
}*/

void BT::postorder()
{
  int top=-1;
  BT *stack[100];
  BT *ptr=root;
  do
  {
    for(;ptr;ptr=ptr->left)
    {
      cout<<ptr->data<<" ";
      stack[++top]=ptr;
    }
    if(top>=0)
      ptr=stack[top--];
    else
      break;
    ptr=ptr->right;
  }while(1);
}

void BT::parent(BT *node, int key)
{
  if(node->left->data==key || node->right->data==key)
  {
    cout<<"\nParent is: "<<node->data;
    return;
  }
  if(node==NULL)
    return;
  parent(node->left,key);
  parent(node->right,key);
}

void BT::ancestor(BT *node, int key, int stack[], int top)
{
  stack[++top]=node->data;
  if(node->data==key)
  {
    cout<<"\n";
    for(int i=0;i<top;i++)
      cout<<stack[i]<<" -> ";
    return;
  }
  if(node==NULL)
  {
    stack[top--];
    return;
  }
  ancestor(node->left,key,stack,top);
  ancestor(node->right,key,stack,top);
}

int BT::leaf_count(BT *node, int prev_count)
{
  static int count=0;
  if(node->left==NULL && node->right==NULL && node!=NULL)
    ++count;
  if(node==NULL)
  {
    return count-prev_count;
  }
  leaf_count(node->left,prev_count);
  leaf_count(node->right,prev_count);
  return count-prev_count;
}

int BT::depth(BT *node)
{
  int ldepth,rdepth;

  if(node==NULL)
    return 0;
  else
  {
    ldepth=depth(node->left);
    rdepth=depth(node->right);
    if(ldepth>rdepth)
      return ldepth+1;
    else
      return rdepth+1;
  }
}

void main()
{
  root=NULL;
  root->left=NULL;
  root->right=NULL;
  clrscr();
  BT l;
  int opt;
  char cont='y';
  int key;
  int prev_count=0;

  while(cont=='y' || cont=='Y')
  {
    cout<<"\n1. Insert"
	<<"\n2. Recursive Print"
	<<"\n3. Preorder"
	<<"\n4. Inorder"
	<<"\n5. Postorder"
	<<"\n6. Count leaf nodes"
	<<"\n7. Depth"
	<<"\n8. Ancestors"
	<<"\n9. Parent"
	<<"\n10. Exit"
	<<"\n\nYour choice: ";
    cin>>opt;

    switch(opt)
    {
      case 1: cout<<"\nEnter data: ";
	      BT *node=new BT;
	      cin>>node->data;
	      node->left=NULL;
	      node->right=NULL;
	      cout<<"\nEnter position string(L=left, R=right, ROOT=root node): ";
	      char pos[20];
	      gets(pos);
	      l.insert(root, pos, node,0);
	      break;
      case 2: l.recur_print(root); break;
      case 3: l.preorder(); break;
      case 4: l.inorder(); break;
      case 5: l.postorder(); break;
      case 6: int count=l.leaf_count(root,prev_count);
	      prev_count+=count;
	      cout<<"\nNo. of leaf nodes = "<<count; break;
      case 7: cout<<"\nDepth is: "<<l.depth(root);
	      break;
      case 8: cout<<"\nEnter key: ";
	      cin>>key;
	      if(key==root->data)
		cout<<"\nRoot has no ancestors!";
	      else
	      {
		int stack[100];
		l.ancestor(root,key,stack,-1);
	      }
	      break;
      case 9: cout<<"\nEnter key: ";
	      cin>>key;
	      if(key==root->data)
		cout<<"\nRoot has no parent!";
	      else
		l.parent(root,key);
	      break;
      case 10: exit(0);
    }

    cout<<"\n\nContinue?(y/n): ";
    cin>>cont;
  }
  getch();
}