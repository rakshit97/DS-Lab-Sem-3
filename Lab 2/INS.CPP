#include<iostream.h>
#include<conio.h>

void main()
{
  clrscr();
  int a[50],i,j,temp,n;
  cout<<"Enter the size: ";
  cin>>n;
  cout<<"\nEnter the data: ";
  for(i=0;i<n;i++)
    cin>>a[i];

  for(i=1;i<n;i++)
  {
    for(j=i;j>0;j--)
    {
      if(a[j]<a[j-1])
      {
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
      }
      else
	break;
    }
  }
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";

  getch();
}