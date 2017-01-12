#include<iostream.h>
#include<conio.h>

void main()
{
  clrscr();
  int i, a[20], n, x, flag=0;

  cout<<"Enter size: ";
  cin>>n;
  cout<<"\nEnter data: \n";
  for(i=0;i<n;i++)
    cin>>a[i];
  cout<<"\nEnter no. to be searched: ";
  cin>>x;

  for(i=0;i<n;i++)
  {
    if(a[i]==x)
    {
      cout<<"\nFound at position: "<<i+1;
      flag=1;
    }
  }
  if(flag==0)
    cout<<"\nNot found";

  getch();
}