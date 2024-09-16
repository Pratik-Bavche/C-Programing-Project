#include<iostream>
#include<fstream>
using namespace std;
class staff
{
  protected:
      int code;
      char name[20];
  public:
      void getstaff()
      {
    cout<<"\n\nEnter code :";
    cin>>code;
    cout<<"Enter name :";
    cin>>name;
      }
      void dispstaff()
      {
       cout<<"\nNAME       :"<<name;
       cout<<"\nCODE       :"<<code;
      }
};
class teacher : public staff
{
      char sub[20];
      char pub[20];
  public:
  	void create()
      {
    getstaff();
    cout<<"Enter Subject :";
    cin>>sub;
    cout<<"Enter Publication :";
    cin>>pub;
      }
      void create(int M)
      {
      	cout<<"Teacher Srno:"<<M;
     dispstaff();
     cout<<"\nSUBJECT    :"<<sub;
     cout<<"\nPUBLICATION:"<<pub;
      }
      void disatfile()
      {
        ofstream fout;
     	fout.open("Teacherdata.txt",ios::out);
     	fout<<"\nTeacher Data";
        fout<<"\nNAME       :"<<name;
        fout<<"\nCODE       :"<<code;
        fout<<"\nSUBJECT    :"<<sub;
        fout<<"\nPUBLICATION:"<<pub;
      }
};
class student : public staff
{
       float per;
   public:
    void create()
    {
       getstaff();
       cout<<"Enter Percentage  :";
       cin>>per;
    }
    void create(int M)
    {
    	cout<<"Student Srno:"<<M;
       dispstaff();
       cout<<"\nPercentage      :"<<per;
    }
     void disatfile()
      {
        ofstream fout;
     	fout.open("Studentdata.txt",ios::out);
     	fout<<"\nStudent Data";
        fout<<"\nNAME       :"<<name;
        fout<<"\nCODE       :"<<code;
        fout<<"\nPercentage      :"<<per;
      }
};
int main()
{
teacher o1t[10];
student  o1o[10];
int choice,i;
char test;
while(1)
{
int count;
start:
   cout<<"\n=====COLLEGE MANAGEMENT SYSTEM=====\n\n\n";
   cout<<"Choose Category of Information\n";
   cout<<"1)   Teachers\n";
   cout<<"2)   Student\n";
   cout<<"3)   Exit\n";
   cout<<"Enter your choice:";
   cin>>choice;
   switch(choice)
   {
      case 1 :  while(1)
        {
        cout<<"\n=====TEACHERS INFORMATION=====\n\n";
        cout<<"\nChoose your choice\n";
        cout<<"1) Enter Details\n";
        cout<<"2) Display Details\n";
        cout<<"3) Go to Main Menu\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
         case 1 :  for(count=0,i=0;i<10;i++)
               {
                 cout<<endl;
                 o1t[i].create();
                 count++;
                 cout<<endl;
                 cout<<"\n\nAre you Interested in entering data\n";
                 cout<<"Enter Y or N:";
                 cin>>test;
                 if(test=='y' || test=='Y')
                continue;
		 else goto out1;
                 }
                 out1:
                 break;
         case 2 : int m; m=1;
		 for(i=0;i<count;i++)
               {
                cout<<endl;
                 o1t[i].create(m);
                 m++;
                 cout<<endl;
               }
         break;
        case 3 :
		 for(i=0;i<count;i++)
               {
                cout<<endl;
                 o1t[i].disatfile();
                 
                 cout<<endl;
               }
           break;
         case 4 :goto start;
       default: cout<<"\nEnter choice is invalid\ntry again\n\n";
         }
         }
      case 2 :   while(1)
         {
        cout<<"\n=====STUDENT INFORMATION=====\n\n";
        cout<<"\nChoose your choice\n";
        cout<<"1) Enter Details \n";
        cout<<"2) Display Details\n";
        cout<<"3) Go to Main Menu\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
         case 1 : for(count=0,i=0;i<10;i++)
               {
                cout<<endl;
                o1o[i].create();
                 count++;
                 cout<<endl;
                 cout<<"\n\nAre you Interested in entering data\n";
                 cout<<"Enter Y or N:";
                 cin>>test;
                 if(test=='y' || test=='Y')
                continue;
		 else goto out2;
                 }
                 out2:
                 break;
         case 2 :int m;
         m=1;
		  for(i=0;i<count;i++)
               {
                cout<<endl;
                 o1o[i].create(m);
                 m++;
                 cout<<endl;
               }
                break;
                case 3 :for(i=0;i<count;i++)
               {
                cout<<endl;
                 o1o[i].disatfile();
                cout<<endl;
               }
           break;
         case 4 : goto start;
         default: cout<<"\nInvalid choice\ntry again\n\n";
         }
         }
      case 3 : goto end;
    }
   }
 end:
 	{
	 }
 }