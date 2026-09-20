#include<iostream>
using namespace std;
void printND(int n){
	for(int i =1; i< n; i++){
		 cout<<"I"<<i;
	 for(int j =i+1; j<n+1; j++ ){
	    cout<<"*"<<"U"<<j;
	 }
	 cout<<"+";
	 
	}
	cout<<"I"<<n;
}
int main(){
	int n;
	cout<<"enter dimension for array ";
	cin>> n;
	printND(n);	
	
}