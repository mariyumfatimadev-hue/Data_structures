#include<iostream>
#include<cstring>
#include"Stack.h"
using namespace std;

class LargeNo{
public:
    void addNo(const char num1[], const char num2[]){
        Stack<int> operandStack1(26);
        Stack<int> operandStack2(26);
        Stack<int> resultStack(26);
        for(int i = 0; i < strlen(num1); i++){
            operandStack1.push(num1[i] - '0');
        }
        for(int i = 0; i < strlen(num2); i++){
            operandStack2.push(num2[i] - '0');
        }
        int carry = 0;

        while(!operandStack1.isempty() || !operandStack2.isempty()){
            int sum = carry;
            if(!operandStack1.isempty()){
                sum += operandStack1.pop();
            }
            if(!operandStack2.isempty()){
                sum += operandStack2.pop();
            }
            resultStack.push(sum % 10);   
            carry = sum / 10;          
        }

        if(carry != 0){
            resultStack.push(carry);
        }

        // f: pop karke print
        while(!resultStack.isempty()){
            cout << resultStack.pop();
        }
        cout << endl;
    }
};

int main(){
    char num1[26];
    char num2[26];

    cout << "Enter first number (max 25 digits): ";
    cin.getline(num1, 26);
    cout << "Enter second number (max 25 digits): ";
    cin.getline(num2, 26);

    LargeNo obj;
    cout << "Sum: ";
    obj.addNo(num1, num2);

    return 0;
}