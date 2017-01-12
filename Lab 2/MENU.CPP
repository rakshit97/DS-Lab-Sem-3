#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{
  clrscr();
  char a[50],b[50];
  int i,j,k,l1,l2,choice,flag=0;
  cout<<"1. Find length of a string."
      <<"\n2. Concatenate two strings."
      <<"\n3. Find the greater string."
      <<"\n4. Insert a substring."
      <<"\n5. Delete a substring."
      <<"\n\nEnter you choice: ";
      cin>>choice;

  switch(choice)
  {
    case 1:  clrscr();
	     cout<<"Enter the string: ";
	     gets(a);
	     for(i=0;a[i]!='\0';i++);
	     cout<<"\nLength = "<<i;
	     break;

    case 2:  clrscr();
	     cout<<"Enter 1st string: ";
	     gets(a);
	     for(i=0;a[i]!='\0';i++);
	     l1=i;
	     cout<<"\nEnter 2nd string: ";
	     gets(b);
	     for(i=0;b[i]!='\0';i++);
	     l2=i;
	     for(i=0;i<l2;i++)
	       a[l1+i]=b[i];
	     a[l1+l2]='\0';
	     cout<<"\nConcatenated string: ";
	     puts(a);
	     break;

    case 3:  clrscr();
	     cout<<"Enter 1st string: ";
	     gets(a);
	     for(i=0;a[i]!='\0';i++);
	     l1=i;
	     cout<<"\nEnter 2nd string: ";
	     gets(b);
	     for(i=0;b[i]!='\0';i++);
	     l2=i;
	     if(l1>l2)
	       cout<<"\nString 1 is greater";
	     else if(l1<l2)
	       cout<<"\nString 2 is greater";
	     else
	       cout<<"\nBoth strings are equal";
	     break;

    case 4:  clrscr();
	     cout<<"Enter main string: ";
	     gets(a);
	     for(i=0;a[i]!='\0';i++);
	     l1=i;
	     cout<<"\nEnter substring: ";
	     gets(b);
	     for(i=0;b[i]!='\0';i++);
	     l2=i;
	     cout<<"\nEnter position: ";
	     int pos;
	     cin>>pos;
	     for(i=l1+l2-1;i>pos;i--)
	       a[i]=a[i-l2];
	     for(i=0;i<l2;i++)
	       a[pos+i]=b[i];
	     a[l1+l2]='\0';
	     cout<<"\nFinal string: ";
	     puts(a);
	     break;
    case 5:  clrscr();
	     cout<<"Enter main string: ";
	     gets(a);
	     for(i=0;a[i]!='\0';i++);
	     l1=i;
	     cout<<"\nEnter substring: ";
	     gets(b);
	     for(i=0;b[i]!='\0';i++);
	     l2=i;
	     for(i=0;i<l1;i++)
	     {
	       if(a[i]==b[0])
	       {
		 pos=i;
		 for(j=i+1,k=1;j<l1,k<l2;j++,k++)
		 {
		   if(a[j]!=b[k])
		   {
		     flag=1;
		     break;
		   }
		 }
		 if(flag==0)
		 {
		   for(i=pos;i<l1;i++)
		     a[i]=a[i+l2];
		   a[l1-l2]='\0';
		   break;
		 }
	       }
	     }
	     cout<<"\nFinal string: ";
	     puts(a);
  }
  getch();
}


