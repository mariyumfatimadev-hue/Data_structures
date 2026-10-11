#include <iostream>
#include "QUEUE_class.h" 

using namespace std;

struct Job {
    int pages;
    int originalIndex;
};

int calculatePrintTime(int pages[], int n, int k) {
    Queue<Job> q;
    
    for (int i = 0; i < n; i++) {
        q.enqueue({pages[i], i});
    }
    
    int totalTime = 0;
    
    while (!q.isEmpty()) {
        Job current = q.dequeue();
        current.pages--; 
        totalTime++;    
        
        if (current.originalIndex == k && current.pages == 0) {
            return totalTime;
        }
        
        if (current.pages > 0) {
            q.enqueue(current);
        }
    }
    
    return totalTime;
}

int main() {
    int pages1[] = {3, 3, 1, 2};
    int n1 = 4;
    int k1 = 0;
    cout << "Example 1 Output: " << calculatePrintTime(pages1, n1, k1) << endl; // Expected: 8

    int pages2[] = {2, 2, 2, 3, 2};
    int n2 = 5;
    int k2 = 3;
    cout << "Example 2 Output: " << calculatePrintTime(pages2, n2, k2) << endl; // Expected: 11

    return 0;
}