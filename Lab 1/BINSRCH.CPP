#include<iostream.h>
#include<conio.h>

void main()
{
  clrscr();
  int i, n, x, mid=0, midpos, flag=0, start, end, a[20];

  cout<<"Enter size: ";
  cin>>n;
  cout<<"\nEnter the data(in increasing order): \n";
  for(i=0;i<n;i++)
    cin>>a[i];
  cout<<"\nEnter term to be searched: ";
  cin>>x;

  start=0;
  end=n-1;
  for(i=0;i<n;i++)
  {
    midpos=(start+end)/2;
    mid=a[midpos];
    if(x<mid)
      end=midpos;
    if(x>mid)
      start=midpos;
    if(x==mid)
    {
      flag=1;
      cout<<"\nFound at position: "<<midpos+1;
      break;
    }
  }
  if(flag==0)
    cout<<"\nNot found";

  getch();
}