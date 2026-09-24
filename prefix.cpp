#include<iostream>
#include"Stack.h"
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
class prefix{
    string data;
    Stack<char> s;
    public:
        prefix(string d){
            data = d;
        }
    int precedence(char op){
        if(op == '+' || op == '-')
           return 1;
        if(op == '*' || op == '/')
        return 2;
    return 0;
}
   string checkdata(){
        string ch = "";
        char temp;
        for(int i =0; i < data.length(); i++){
            if(data[i] >= 'A' && data[i] <= 'Z'){
                ch += data[i];
            }
            else if(data[i] == '+' || data[i]== '*' || data[i]== '/' || data[i]== '-'){
            while(!s.isempty() && precedence(s.Stacktop()) >= precedence(data[i])   ){
            temp = s.pop();
             ch += temp;
            }
            s.push(data[i]);
        }
    }
        while( !s.isempty() ){                                  
        temp = s.pop();
        ch += temp;
    }
    return ch;
    }        
};
int main(){
    string eq;
	cout<<"enter your equation";
	getline(cin  ,eq);
	prefix obj(eq);
    cout<<"your answe is     ";
	cout<<obj.checkdata();
	return 0;
}