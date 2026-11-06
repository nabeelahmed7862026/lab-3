
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class MyQueue {
private:
    queue<int> q;

public:

    // Enqueue: Insert element
    void enqueue(int value) {
        q.push(value);
    }

    // Dequeue: Remove front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = q.front();
        q.pop();
        return value;
    }

    // Front: Return first element
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return q.front();
    }

    // Check Empty
    bool isEmpty() {
        return q.empty();
    }

    // Display Queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        queue<int> temp = q;

        cout << "Queue Elements: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

    // Reverse First K Elements
    void reverseFirstK(int k) {

        int n = q.size();

        // Handle invalid or unnecessary cases
        if (k <= 1) {
            cout << "No Reversal Needed!" << endl;
            return;
        }

        if (k > n) {
            k = n;
        }

        stack<int> s;

        // Step 1: Push first K elements into stack
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Pop stack elements back into queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move remaining elements to the rear
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << "First " << k
            << " elements reversed successfully!" << endl;
    }
};

// Main Function
int main() {

    MyQueue q;

    int n, value, k;

    cout << "Enter number of Queue elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }

    // Read Queue elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        q.enqueue(value);
    }

    cout << "\nOriginal ";
    q.display();

    // Read K
    cout << "\nEnter value of K: ";
    cin >> k;

    // Reverse first K elements
    q.reverseFirstK(k);

    // Display updated Queue
    cout << "\nFinal ";
    q.display();

    return 0;
}
