#include<iostream.h>
#include<conio.h>

void main()
{
  clrscr();
  int i, j, a[10][10], b[10][10], c[10][10], n;

  cout<<"Enter size of the matrices: ";
  cin>>n;
  cout<<"\nEnter data for 1st matrix: \n";
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin>>a[i][j];
  cout<<"\nEnter data for 2nd matrix: \n";
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin>>b[i][j];

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(a[i][j]>b[i][j])
	c[i][j]=a[i][j];
      if(a[i][j]<b[i][j])
	c[i][j]=b[i][j];
      else
	c[i][j]=a[i][j];
    }
  }

  cout<<"\nMax array: \n";
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      cout<<c[i][j]<<" ";
    cout<<"\n";
  }
  getch();
}