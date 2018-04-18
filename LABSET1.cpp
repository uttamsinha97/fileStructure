//Write a C++ program to read n names from the standard input, write the names to the file OUT.txt and also create a file called as REVERSE_CASE.txt and copy the names into this file by reversing the names of the OUT.txt file. Display the contents of both files on the standard output.

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    fstream f;
    char temp;
    string fname[20],fn[20],str;
    int i,j,k,n,p;
    cout<<"Enter the number of names you want to enter:\n";
    cin>>n;
    f.open("inputfile.txt",ios::out);
    cout<<"Enter the Names :\n";
    for(i=1;i<=n;i++)
    {
        cin>>fname[i];
	f<<fname[i]<<endl;
    }
    f.close();
    f.open("reverse_case.txt",ios::out);
    for(j=1;j<=n;j++)
    {
        str=fname[j];
        k=str.length()-1;
        p=0;
        while(p<k)
        {
            temp=str[p];
            str[p]=str[k];
            str[k]=temp;
            p++;
            k--;
        }
        f<<str<<endl;
    }
    f.close();
   f.open("reverse_case.txt",ios::in);
    for(i=1;i<=n;i++)
    {
        f>>fn[i];
    }
    f.close();
  /*   f.open("reverse_case.txt",ios::in);
     f.seekg(0,ios::end);
     int size=f.tellg();
     char a;
     for(i=1;i<=n;i++)
     {
         f.seekg(-i,ios::end);
         a=f.get();
         f<<fname;
     }
*/
     cout<<"The Reverse words are:\n";
     for(int i=n;i>=0;i--)
    {
        f<<fn[i];
        cout<<fn[i];
        cout<<"\n";
    }
    f.close();
    return 0;
}

