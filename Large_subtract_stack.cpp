#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
bool isGreaterOrEqual(string num1, string num2) {
    if (num1.length() != num2.length())
        return num1.length() > num2.length();
    return num1 >= num2;
}
string subtractLargeNumbers(string num1, string num2) {
    if (!isGreaterOrEqual(num1, num2)) {
        return "-" + subtractLargeNumbers(num2, num1);
    }
    stack<int> s1, s2, resultStack;
    for (char c : num1) {
        s1.push(c - '0');
    }
    for (char c : num2) {
        s2.push(c - '0');
    }
    int borrow = 0;
    while (!s1.empty() || !s2.empty()) {
        int d1 = 0, d2 = 0;
        
        if (!s1.empty()) {
            d1 = s1.top();
            s1.pop();
        }
        
        if (!s2.empty()) {
            d2 = s2.top();
            s2.pop();
        }
            int sub = d1 - d2 - borrow;
        
        if (sub < 0) {
            sub += 10;     
            borrow = 1;  
        } else {
            borrow = 0;   
        }
        
        resultStack.push(sub);
    }
    
    string result = "";
    bool leadingZero = true;
    
    while (!resultStack.empty()) {
        int digit = resultStack.top();
        resultStack.pop();
        if (leadingZero && digit == 0 && !resultStack.empty()) {
            continue; 
        }
        leadingZero = false;
        result += to_string(digit);
    }
    
    return result.empty() ? "0" : result;
}

int main() {
    string num1, num2;
    
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;
    string difference = subtractLargeNumbers(num1, num2);
    cout << "Difference: " << difference << endl;
    return 0;
}