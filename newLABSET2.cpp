//LABSET 2
/* Write a C++ program to read and write student objects with fixed-length records and the fields delimited by
 “|” and records delimited by “#”. Implement modify ( ), display () and search ( ) methods
 by performing pack and unpack operations.*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#define LEN 32
using namespace std;
class student
{
	char name[20],usn[11],sem[3],dept[10],buf[30];
	public:
	void display();
	void pack();
	void unpack();
	void search();
	void read();
	void modify();
	void write();
};
void student :: pack()
{
	strcpy(buf,usn);
	strcat(buf,"|");
	strcat(buf,name);
	strcat(buf,"|");
    strcat(buf,dept);
    strcat(buf,"|");
    strcat(buf,sem);
	for(int i=strlen(buf); i<LEN ; i++)
		strcat(buf,"#");
	strcat(buf,"\n");
}
void student :: unpack()
{
	strcpy(usn,strtok(buf,"|"));
	strcpy(name,strtok(NULL,"|"));
	strcpy(dept,strtok(NULL,"|"));
	strcpy(sem,strtok(NULL,"#"));
}
void student :: read()
{
    cout<<"Enter the USN: ";
	cin>>usn;
    cout<<"Enter the NAME : ";
	cin>>name;
	cout<<"Enter the DEPT : ";
	cin>>dept;
	 cout<<"Enter the SEM: ";
	cin>>sem;
}
void student::write()
{
    ofstream fout;
	fout.open("newfile.txt",ios::app);
	fout<<buf;
	fout.close();
	cout<<"\nStudent Record Added\n";
}
void student :: display()
{
	ifstream fin;
	fin.open("newfile.txt");
	while(!fin.eof())
	{
		fin>>buf;
		if(fin.fail()) break;
		unpack();
		cout<<"\nStudent Found : "<<"\nUSN : "<<usn<<"\nNAME : "<<name<<"\nDEPT : "<<dept<<"\nSEMESTER: "<<sem<<endl;
	}
	fin.close();
}
void student :: search()
{
	ifstream fin;
	fin.open("newfile.txt");
	char key[LEN];
	cout<<"Enter the key : ";
	cin>>key;
	int found = 0;
	while(!fin.eof())
	{
		fin>>buf;
		if(fin.fail())
            break;
		unpack();
		if(!strcmp(usn,key))
		{
			cout<<"\nStudent Found : "<<"\nUSN : "<<usn<<"\nNAME : "<<name<<"\nDEPT : "<<dept<<"\nSEMESTER: "<<sem<<endl;
			found = 1;
		}
	}
	if(found==0)
	cout<<"Student Not found!!\n";
	fin.close();
	return;
}
void student :: modify()
{
	fstream f;
	f.open("newfile.txt",ios::in|ios::out);
	char key[LEN];
	cout<<"Enter the key USN: ";
	cin>>key;
	while(!f.eof())
	{
		f>>buf;
		if(f.fail()) break;
		unpack();
		if(!strcmp(usn,key))
		{
			cout<<"\nStudent Found \nEnter the Name \n";
			cin>>name;
			cout<<"Enter the new DEPT:\n";
			cin>>dept;
			cout<<"\nEnter the new SEM: \n";
			cin>>sem;
			pack();
			f.seekp((int)f.tellg()-LEN,ios::beg);
			f<<buf;
			f.close();
			return;
		}
	}
	cout<<"\nStudent Not found\n";
	f.close();
}
int main()
{
	student s;
	int ch;
	while(1)
	{
            cout<<"Enter Your Choice for Fixed Length Record\n";
            cout<<"1.Read\n2.Pack\n3.Write\n4.Search\n5.Modify\n6.Display\n7.Exit\n";
	        cin>>ch;
	        switch(ch)
	        {
                case 1:s.read();
                    break;

                case 2:s.pack();
                    break;

                case 3:s.write();
	                   break;

                case 4:s.search();
	                  break;

                case 5:s.modify();
	                  break;

                case 6:s.display();
                        break;
                case 7: exit(0);
                        break;
                default: cout<<"Invalid choice\n";
	       }
    }
    return 0;
}
