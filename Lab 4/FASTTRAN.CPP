#include<iostream.h>
#include<conio.h>

class sparse
{
  public:
  int rows,cols,val;
}s[50],s1[50];

int fst[50]={0};

void fast(int n)
{
  int i,j,c=0,startpos[51]={0};
  startpos[0]=1;
  for(i=1;i<=n;i++)
    startpos[i]=startpos[i-1]+fst[i-1];
  s1[0].rows=s[0].rows;
  s1[0].cols=s[0].cols;
  s1[0].val=s[0].val;
  for(j=1;j<=s1[0].val;j++)
  {
    s1[startpos[s[j].cols]].rows=s[j].cols;
    s1[startpos[s[j].cols]].cols=s[j].rows;
    s1[startpos[s[j].cols]].val=s[j].val;
    startpos[s[j].cols]++;
  }
}

void display(int m, int n, int flag)
{
  int b[20][20]={0};
  int i,j;
  for(i=1;i<=s[0].val;i++)
  {
    if(flag==0)
      b[s[i].rows][s[i].cols]=s[i].val;
    else
      b[s1[i].rows][s1[i].cols]=s1[i].val;
  }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      cout<<b[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void main()
{
  clrscr();
  int a[20][20],i,j,m,n,count=0;
  cout<<"Enter no. of rows: ";
  cin>>m;
  cout<<"\nEnter no. of columns: ";
  cin>>n;
  cout<<"\nEnter elements: ";
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      cin>>a[i][j];
      if(a[i][j]!=0)
      {
	s[count+1].rows=i;
	s[count+1].cols=j;
	s[count+1].val=a[i][j];
	fst[j]++;
	count++;
      }
    }
  }
  s[0].rows=m;
  s[0].cols=n;
  s[0].val=count;
  cout<<"\n\nOriginal matrix: \n";
  display(m,n,0);
  fast(n);
  cout<<"\n\nTransposed matrix: \n";
  display(m,n,1);
  getch();
 }