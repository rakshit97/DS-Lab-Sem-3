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

  for(i=0;i<n;i++)
  {
    int ele=a[i];
    for(j=i+1;j<n;j++)
    {
      if(ele==a[j])
      {
	for(int k=j;k<n;k++)
	  a[k]=a[k+1];
	n--;
      }
    }
  }
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";

  getch();
}
