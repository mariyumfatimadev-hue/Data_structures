#include<iostream>
#include"Stack.h"
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
class anbn{
    string s;
    Stack<char> st;
public:
bool checkAnBn(string s){
    bool seenB = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a'){
            if(seenB){
                return false;      
            }
            st.push(s[i]);
        }
        else if(s[i] == 'b'){
            seenB = true;
            if(st.isempty()){
                return false; 
            }
            st.pop();
        }
        else{
            return false;  
        }
    }
    if(!st.isempty()){
        return false;           
    }

    return true;
}
};
int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;
    anbn obj;
    if(obj.checkAnBn (input)){
        cout << input << " is a valid a^n b^n string." << endl;
    }
    else{
        cout << input << " is NOT a valid a^n b^n string." << endl;
    }
    return 0;
}
