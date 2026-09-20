#include<iostream>
#include<fstream>
#include<stdio.h>
#include<windows.h>
using namespace std;

struct Student
{
int roll;
char name[30];
Student():roll(0)
{
  strcpy(name,"none");
}
};
void addToStudentUnBuffered(int N)
{
ofstream ofs("studentdatabase.txt",ios::binary|ios::out);
 Student s;
for (int i=1; i<N; i++)
{
s.roll = i;
ofs.write((char*)(&s),sizeof(Student));
}
ofs.close();
}

 void readAllRecordsUnBuffered(int N ){
 ifstream ofs("studentdatabase.txt",ios::binary|ios::in);
 Student s;
for (int i=1; i<N; i++)
{
s.roll = i;
ofs.read((char*)(&s),sizeof(Student));
}
ofs.close();
}
int main(){
	int N;
	cout<<"enter size of array";
	cin>> N;
addToStudentUnBuffered(N);
SYSTEMTIME systime;
cout<<"\nWriting Records to File one by one";
GetLocalTime(&systime);
cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
addToStudentUnBuffered(N);
GetLocalTime(&systime);
cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
readAllRecordsUnBuffered(N);

}