#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"enter size for array";
	cin>>size;
	int target;
	cout<<"enter your target to find sum";
	cin>> target;
	int num[size];
	cout<<"enter array";
	for(int i =0; i< size; i++){
	cin>>num[i];
	}
	//sort
	for(int i =0; i< size; i++){
		for(int j =0; j< size; j++){
			if(num[i]+num[j] == target)
			 cout<<"("<<num[i]<<","<<num[j]<<")";
		}
	}
	return 0;
	
}