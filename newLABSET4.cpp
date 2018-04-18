/*4. Write a C++ program to write student objects with Fixed – Length records using any
suitable record structure and to read from this file a student record using RRN. */
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#define LEN 45
using namespace std;
class student
{
	char usn[11];
	char name[10];
	char dept[15];
	char sem[5];
	char buffer[45];
public:
	void read();
	void pack();
	void unpack();
	void write();
	void search();
};
void student::read()
{
	cout<<"Enter the usn :"<<endl;
	cin>>usn;
	cout<<"Enter the name :"<<endl;
	cin>>name;
	cout<<"Enter the department :"<<endl;
	cin>>dept;
	cout<<"Enter the semester :"<<endl;
	cin>>sem;
}
void student :: pack()
{
    strcpy(buffer,usn);
	strcat(buffer,"|");
    
	strcat(buffer,name);
    strcat(buffer,"|");
    
    strcat(buffer,dept);
    strcat(buffer,"|");
    
    strcat(buffer,sem);
    for(int i=strlen(buffer); i<LEN ; i++)
		strcat(buffer,"#");
	strcat(buffer,"\n");
}
void student::write()
{

	fstream f;
    f.open("student40.txt",ios::app | ios::out);
	f<<buffer;
	f.close();
	cout<<"\nStudent Record Added\n";
}
void student::search()
{
	int rrn;
	fstream f;
	student s;
	f.open("student40.txt",ios::in);
	if(f==NULL)
	{
		cout<<"File opening error"<<endl;
		return;
	}
	cout<<"Enter the rrn number of the record to be searched"<<endl;
	cin>>rrn;
	rrn=rrn-1;
	int num=rrn*45;
	f.seekg(num,ios::beg);
	f.getline(s.usn,11,'|');
	if(f==NULL)
	{
		cout<<"Record not found with the rrn : "<<rrn+1<<endl;
		return;
	}
	f.getline(s.name,10,'|');
      f.getline(s.dept,15,'|');
      f.getline(s.sem,5,'#');
	cout<<"\nRecord is found with RRN number : "<<rrn+1<<endl;
	cout<<"Usn\t\tName\t\tBranch\t\tSem"<<endl;
	cout<<"\n"<<s.usn<<"\t\t"<<s.name<<"\t\t"<<s.dept<<"\t\t"<<s.sem;
	f.close();
}

int main()
{
	int ch;
	student s;
	while(1)
	{
		cout<<"\nEnter the choice "<<"\n1.Write Record\t 2.Search Record by RRN number\t 3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: s.read();
					 s.pack();
					 s.write();
                     break;
			case 2: s.search();
                     break;
			case 3:exit(0);
                    break;
            default:cout<<"\nINVALID CHOICE\n";
		}
	}
}
