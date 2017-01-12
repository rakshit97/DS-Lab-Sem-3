#include<iostream.h>
#include<conio.h>

void main()
{
  clrscr();
  int i, j, a[20], n, s, is;

  cout<<"Enter size: ";
  cin>>n;
  cout<<"\nEnter the data: ";
  for(i=0;i<n;i++)
    cin>>a[i];

  for(i=0;i<n;i++)
  {
    s=a[i];
    is=i;
    for(j=i;j<n;j++)
    {
      if(s>a[j])
      {
	s=a[j];
	is=j;
      }
    }
    int temp=a[i];
    a[i]=a[is];
    a[is]=temp;
  }

  for(i=0;i<n;i++)
    cout<<a[i]<<" ";

  getch();
}