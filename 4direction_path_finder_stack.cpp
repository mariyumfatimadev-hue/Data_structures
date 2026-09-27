#include <iostream>
#include <stack>
using namespace std;
struct Pair {
    int i;
    int j;
};

void findPath(int a[][100], int r, int c, int source_i, int source_j, int dest_i, int dest_j) {
    stack<Pair> st;
    Pair s = {source_i, source_j};
    st.push(s);
    a[source_i][source_j] = 3;
    
    bool found = false;
    
    while (!st.empty()) {
        Pair curr = st.top();
        if (curr.i == dest_i && curr.j == dest_j) {
            cout << "Found path!" << endl;
            found = true;
            break;
        }
        if (curr.j - 1 >= 0 && a[curr.i][curr.j - 1] == 0) {
            a[curr.i][curr.j - 1] = 3;
            Pair next = {curr.i, curr.j - 1};
            st.push(next);
        }
        else if (curr.j + 1 < c && a[curr.i][curr.j + 1] == 0) {
            a[curr.i][curr.j + 1] = 3;
            Pair next = {curr.i, curr.j + 1};
            st.push(next);
        }
        else if (curr.i - 1 >= 0 && a[curr.i - 1][curr.j] == 0) {
            a[curr.i - 1][curr.j] = 3;
            Pair next = {curr.i - 1, curr.j};
            st.push(next);
        }
        else if (curr.i + 1 < r && a[curr.i + 1][curr.j] == 0) {
            a[curr.i + 1][curr.j] = 3;
            Pair next = {curr.i + 1, curr.j};
            st.push(next);
        }
        else {
            st.pop();
        }
    }
    
    if (!found) {
        cout << "Path not found!" << endl;
    }
}

int main() {
    int r = 4, c = 5;
    int a[100][100] = {
        {1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0}
    };
    
    findPath(a, r, c, 0, 1, 3, 4);
    
    return 0;
}