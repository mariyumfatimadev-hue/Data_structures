#include<iostream>
#include"Stack.h"
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
class postfix{
	string data;
	Stack<int> s;
	public:
		postfix(string d){
			data = d;
		}
		int x, y,n;
	void checkoperand_operator(){
		for(int i =0; i< sizeof(data); i++ ){
			if(data[i] >= '0' && data[i] <= '9'){
				s.push(data[i] - '0');
			}
			else if(data[i] == '+' || data[i]== '*' || data[i]== '/' || data[i]== '-'){
			  x = s.pop();
              y = s.pop();
              if(data[i] == '+'){
                n = y + x;
                }
              else if(data[i] == '-'){
                  n = y - x;
              }
              else if(data[i] =='*'){
                  n = y * x;
              }
              else if(data[i] == '/'){
              	if(x != 0){
                  n = y / x;
              }
          }
            else
              cout<<"those are comparison operators;";
              
               s.push(n);
          }
        }
                
		}
	int getResult()
	{
	 return s.pop();
 }	
 
 
};
int main(){
	string eq;
	cout<<"enter your equation";
	getline(cin  ,eq);
	postfix obj(eq);
	obj.checkoperand_operator();
	cout<<endl;
	cout<<"your answer is:     ";
	cout<<obj.getResult();
	return 0;
}