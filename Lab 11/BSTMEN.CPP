#include<iostream.h>
#include<conio.h>
#include<process.h>

class bst
{
 	bst *lchild;
 	int data;
 	bst *rchild;
	
	public:
 	bst(int ele=0)
 	{
  		lchild=NULL;
   		rchild=NULL;
 		data=ele;
	}

 	void insert(int);
 	void search(int);
	void display(bst *);
 	void del(int);
};

bst *root=NULL;

void bst::insert(int ele)
{
	
	bst *temp=new bst(ele); 
      	
	if(root==NULL)
	{
		root=temp;
		return;
	}
	else
      	{
        	bst *curr=root, *prev=NULL;
             	while(curr)
             	{
                	prev=curr;
                   	if(temp->data<curr->data) 
			 curr=curr->lchild; 
                   	else if(temp->data>curr->data)      
		  	 curr=curr->rchild;
                   	else
                   	{ 
                        	cout<<"Insertion not possible"; 
                         	return;
                   	}
             	}
	
             	if(temp->data>prev->data) 
                 prev->rchild=temp;
             	else if(temp->data<prev->data)
                 prev->lchild=temp;
      }
      return;
}

void bst::search(int ele)
{
	if (root==NULL)
     	{
    		cout<<"Empty Tree";
          	return;
     	}
     
	bst *curr=root;
     
	while(curr!=NULL)
     	{    
		if(curr->data==ele)
          	{
               		cout<<"Element found";
               		return;
          	}
          	else if(curr->data>ele)   
		 curr=curr->lchild;
          	else
	         curr=curr->rchild;
     	}
     	cout<<"Element not found";
}

void bst::display(bst *ptr) 
{
    	if(ptr)
	{
     		display(ptr->lchild);
     		cout<<" "<<ptr->data;
     		display(ptr->rchild);
    	}
}

void bst::del(int ele)
{
	int top=-1,arr[20],ind=0,flag=0; 
	bst *stack[10],obj;
	bst *ptr=root;

	do
	{
    		for(;ptr;ptr=ptr->lchild) 
    		 stack[++top]=ptr;

    		if(top>=0)      
		 ptr=stack[top--];
    		else            
		 break;

    		if (ptr->data!=ele)
     		 arr[ind++]=ptr->data; 
      		else
     		{
         		cout<<"\n"<<ele<<"Deleted from BST\n"; 
			flag=1;
     		} 
    		ptr=ptr->rchild;
	}while(1);
     	if(flag==0)
	{
		cout<<"\nElement not Found\n"; 
		return;	
	} 
     	else
	{
     		root=NULL;
     		for(int i=0;i<ind;i++) 
	 	 obj.insert(arr[i]);
	}
}

void main()
{
	clrscr();
	bst obj;
	int ch, ele;
	while(1)
	{
		cout<<"\n1.Insert \n2.Search \n3.Delete \n4.Display \nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\nEnter Element:";
			cin>>ele;
			obj.insert(ele);
			break;
			
			case 2:
			cout<<"\nEnter Element:";
			cin>>ele;
			obj.search(ele);
			break;
		
			case 3:
			cout<<"\nEnter Element:";
			cin>>ele;
			obj.del(ele);
			break;

			case 4:
			cout<<"Display";
			obj.display(root);
			break;

			default:
			exit(0);
		}
	}
	getch();
}			
			
			
	
