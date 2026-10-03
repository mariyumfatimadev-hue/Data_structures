#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string* arr;
    int top;
    int capacity;

    void resize() {
        capacity *= 2;
        string* temp = new string[capacity];
        for (int i = 0; i <= top; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
    }

public:
    Stack(int size = 5) {
        capacity = size;
        arr = new string[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(const string& page) {
        if (top == capacity - 1)
            resize();
        arr[++top] = page;
    }

    string pop() {
        if (isEmpty())
            return "";
        return arr[top--];
    }

    void display() const {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

void showMenu() {
    cout << "\n1. Visit Page" << endl;
    cout << "2. Go Back" << endl;
    cout << "3. Display History" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    Stack history;
    string currentPage = "";
    int choice;

    do {
        showMenu();
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string page;
            cout << "Enter page: ";
            getline(cin, page);

            if (currentPage != "")
                history.push(currentPage);
            currentPage = page;
            break;
        }

        case 2:
            if (history.isEmpty()) {
                cout << "No previous pages available." << endl;
            } else {
                currentPage = history.pop();
                cout << "Going Back to: " << currentPage << endl;
            }
            break;

        case 3:
            cout << "\nBrowser History:" << endl;
            if (history.isEmpty()) {
                cout << "No previous pages available." << endl;
            } else {
                cout << currentPage << endl;
                history.display();
            }
            break;

        case 4:
            cout << "Exiting Browser History Manager..." << endl;
            break;

        default:
            cout << "Invalid choice! Please enter 1-4." << endl;
        }

    } while (choice != 4);

    return 0;
}