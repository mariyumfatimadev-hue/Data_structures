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
    ofstream ofs("studentdatabase_unbuffered.txt", ios::binary | ios::out);
    Student s;
    for (int i = 1; i < N; i++)
    {
        s.roll = i;
        ofs.write((char*)(&s), sizeof(Student));   // N alag alag write calls
    }
    ofs.close();
}

void readAllRecordsUnBuffered(int N)
{
    ifstream ifs("studentdatabase_unbuffered.txt", ios::binary | ios::in);
    Student s;
    for (int i = 1; i < N; i++)
    {
        ifs.read((char*)(&s), sizeof(Student));    
    }
    ifs.close();
}


void addToStudentBuffered(int N)
{
    ofstream ofs("studentdatabase_buffered.txt", ios::binary | ios::out);

    Student* buffer = new Student[N];
    for (int i = 1; i < N; i++)
    {
        buffer[i].roll = i;
    }

    ofs.write((char*)buffer, N * sizeof(Student)); 
    ofs.close();
    delete[] buffer;
}

void readAllRecordsBuffered(int N)
{
    ifstream ifs("studentdatabase_buffered.txt", ios::binary | ios::in);

    Student* buffer = new Student[N];
    ifs.read((char*)buffer, N * sizeof(Student));   

    ifs.close();
    delete[] buffer;
}

// ---------- MAIN: TIME COMPARISON ----------
int main()
{
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    SYSTEMTIME start, end;

    // Unbuffered
    cout << "\n--- Unbuffered (record by record) ---";
    GetLocalTime(&start);
    addToStudentUnBuffered(N);
    readAllRecordsUnBuffered(N);
    GetLocalTime(&end);
    cout << "\nStart: " << start.wHour << ":" << start.wMinute << ":" << start.wSecond << ":" << start.wMilliseconds;
    cout << "\nEnd:   " << end.wHour << ":" << end.wMinute << ":" << end.wSecond << ":" << end.wMilliseconds;

    // Buffered
    cout << "\n\n--- Buffered (all at once, chunk) ---";
    GetLocalTime(&start);
    addToStudentBuffered(N);
    readAllRecordsBuffered(N);
    GetLocalTime(&end);
    cout << "\nStart: " << start.wHour << ":" << start.wMinute << ":" << start.wSecond << ":" << start.wMilliseconds;
    cout << "\nEnd:   " << end.wHour << ":" << end.wMinute << ":" << end.wSecond << ":" << end.wMilliseconds;

    return 0;
}