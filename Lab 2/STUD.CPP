#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int i,j,n,temp;
char temp1,temp2[20];

class student
{
  private:
  int roll;
  char name[20],grade;

  public:
  void read();
  void display();
  void sort();
}s[10];

void student::sort()
{
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
      if(s[j].roll>s[j+1].roll)
      {
	temp=s[j].roll;
	s[j].roll=s[j+1].roll;
	s[j+1].roll=temp;
	temp1=s[j].grade;
	s[j].grade=s[j+1].grade;
	s[j+1].grade=temp1;
	strcpy(temp2,s[j].name);
	strcpy(s[j].name,s[j+1].name);
	strcpy(s[j+1].name,temp2);
      }
    }
  }
}

void student::display()
{
  for(i=1;i<=n;i++)
  {
    cout<<"\nRoll no: "<<s[i].roll;
    cout<<"\nName: ";
    puts(s[i].name);
    cout<<"Grade: "<<s[i].grade;
  }
}

void student::read()
{
  cout<<"Enter the no. of students: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cout<<"Enter the roll no: ";
    cin>>s[i].roll;
    cout<<"\nEnter name: ";
    gets(s[i].name);
    cout<<"\nEnter grade: ";
    cin>>s[i].grade;
  }
  sort();
  display();
}

void main()
{
  clrscr();
  student a;
  a.read();
  getch();
}