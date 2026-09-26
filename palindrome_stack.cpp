  #include<iostream>
  #include "Stack.h"
  #include<string>
  #include<cstdlib>
  using namespace std;
  Stack<char> st;
string checkpalindrome(string word){
  	string newpal;

		for(int i = 0; i< word.length(); i++){
		st.push(word[i]);	
		}
		for(int j= 0; j< word.length(); j++){
			if( word[j] >= 'A' && word[j] <= 'Z' || word[j] >= 'a' && word[j] <= 'z' || word[j] >= '0' && word[j]<= '9'){
	   newpal[j]=st.Stacktop();
	   if(newpal[j] == word[j]){
    	cout<<"palindrome";
	}	
	else
	 cout<<"not palindrome";
	 	

}
	   
return newpal;
}
}

int main(){
	string word;
	cout<<"enter pharase or word";
	getline(cin , word);
   string n = checkpalindrome(word);
   cout<<n;
}
  