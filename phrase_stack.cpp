#include<iostream>
#include<string>
#include<cctype>
#include "Stack.h"
using namespace std;
string checkpalindrome(string word){
    string newpal = "";       
    string cleaned = "";      
    if(word.length() == 0){   
        return newpal;
    }

    Stack<char> st(word.length());  
    for(int i = 0; i < word.length(); i++){
        if(isalnum(word[i])){
            cleaned += tolower(word[i]);
            st.push(tolower(word[i]));
        }
    }
    while(!st.isempty()){
        newpal += st.pop();
    }
    if(newpal == cleaned){
        cout << "palindrome" << endl;
    }
    else{
        cout << "not palindrome" << endl;
    }

    return newpal;
}

int main(){
    string word;
    cout << "enter phrase or word: ";
    getline(cin, word);
    string n = checkpalindrome(word);
    cout << "reversed: " << n << endl;
    return 0;
}