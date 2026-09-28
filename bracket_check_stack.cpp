#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

bool isPair(char open, char close){
    if(open == '(' && close == ')')
        return true;
    if(open == '{' && close == '}')
        return true;
    if(open == '[' && close == ']')
        return true;
    return false;
}

bool isBalanced(string expr){
    if(expr.length() == 0){
        return true;
    }

    Stack<char> st(expr.length());

    for(int i = 0; i < expr.length(); i++){
        char ch = expr[i];

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(st.isempty()){
                return false;          
            }
            char top = st.pop();
            if(!isPair(top, ch)){
                return false;         
            }
        }
        
    }

   
    return st.isempty();
}

int main(){
    string expr;
    cout << "Enter a mathematical expression: ";
    getline(cin, expr);

    if(isBalanced(expr)){
        cout << "GOOD" << endl;
    }
    else{
        cout << "BAD" << endl;
    }

    return 0;
}