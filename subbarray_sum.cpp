#include<iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    
    bool found = false;
    
    for(int j = 0; j < size; j++){
        int sum = 0;
        for(int k = j; k < size; k++){
            sum += arr[k];
            if(sum == 0){
                found = true;
                cout << "Subarray from " << j << " to " << k << ": { ";
                for(int m = j; m <= k; m++){
                    cout << arr[m] << " ";
                }
                cout << "}" << endl;
            }
        }
    }
    
    if(!found){
        cout << "No zero-sum subarray found." << endl;
    }
    
    return 0;
}