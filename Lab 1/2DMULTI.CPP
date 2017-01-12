#include<iostream.h>
#include<conio.h>

void main()
{
  clrscr();
  int i, j, a[10][10], b[10][10], c[10][10], n1, m1, n2, m2, sum=0;;

  cout<<"Enter size of the 1st matrix: ";
  cin>>n1>>m1;
  cout<<"Enter size of the 2nd matrix: ";
  cin>>n2>>m2;
  cout<<"\nEnter data for 1st matrix: \n";
  for(i=0;i<n1;i++)
    for(j=0;j<m1;j++)
      cin>>a[i][j];
  cout<<"\nEnter data for 2nd matrix: \n";
  for(i=0;i<n2;i++)
    for(j=0;j<m2;j++)
      cin>>b[i][j];

  if(m1==n2)
  {
    for(i=0;i<n1;i++)
    {
      for(j=0;j<m2;j++)
      {
	for(int k=0;k<n2;k++)
	  sum+=(a[i][k]*b[k][j]);
	c[i][j]=sum;
	sum=0;
      }
    }

    for(i=0;i<n1;i++)
    {
      for(j=0;j<m2;j++)
	cout<<c[i][j]<<" ";
      cout<<"\n";
    }
  }
  else
    cout<<"Error multiplying";

  getch();
}
