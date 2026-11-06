
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1;  // For Enqueue
    stack<int> s2;  // For Dequeue

    // Transfer elements from s1 to s2
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:

    // 1. Enqueue Operation
    void enqueue(int value) {
        s1.push(value);
        cout << value << " inserted successfully!" << endl;
    }

    // 2. Dequeue Operation
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.empty()) {
            transfer();
        }

        int value = s2.top();
        s2.pop();

        return value;
    }

    // 3. Front Element
    int frontElement() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.empty()) {
            transfer();
        }

        return s2.top();
    }

    // 4. Display Elements
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";

        // Display s2 from top to bottom
        stack<int> temp = s2;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        // Display s1 in reverse stack order
        stack<int> temp2 = s1;
        stack<int> temp3;

        while (!temp2.empty()) {
            temp3.push(temp2.top());
            temp2.pop();
        }

        while (!temp3.empty()) {
            cout << temp3.top() << " ";
            temp3.pop();
        }

        cout << endl;
    }

    // Check Empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

// Main Function
int main() {

    QueueUsingStacks q;

    int choice, value;

    do {
        cout << "\n===== QUEUE USING TWO STACKS =====" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Elements" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            if (!q.isEmpty()) {
                cout << "Removed Element: "
                    << q.dequeue() << endl;
            }
            else {
                cout << "Queue is Empty!" << endl;
            }
            break;

        case 3:
            if (!q.isEmpty()) {
                cout << "Front Element: "
                    << q.frontElement() << endl;
            }
            else {
                cout << "Queue is Empty!" << endl;
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Exited Successfully!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 5);

    return 0;
}
