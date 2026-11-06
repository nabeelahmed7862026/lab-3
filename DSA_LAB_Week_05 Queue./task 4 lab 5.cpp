
#include <iostream>
#include <queue>
using namespace std;

class CustomerSupport {
private:
    queue<int> tickets;

public:

    // 1. Enqueue: Add New Ticket
    void enqueue(int ticket_id) {

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID! Enter a 4-digit ID." << endl;
            return;
        }

        // Check duplicate ticket ID
        queue<int> temp = tickets;

        while (!temp.empty()) {
            if (temp.front() == ticket_id) {
                cout << "Ticket ID already exists!" << endl;
                return;
            }
            temp.pop();
        }

        tickets.push(ticket_id);

        cout << "Ticket " << ticket_id
            << " added successfully!" << endl;
    }

    // 2. Dequeue: Resolve Ticket
    void dequeue() {

        if (tickets.empty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }

        cout << "Ticket "
            << tickets.front()
            << " resolved successfully!" << endl;

        tickets.pop();
    }

    // 3. Front: Check Next Ticket
    void front() {

        if (tickets.empty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }

        cout << "Next Ticket to Resolve: "
            << tickets.front() << endl;
    }

    // 4. Display All Pending Tickets
    void display() {

        if (tickets.empty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }

        queue<int> temp = tickets;

        cout << "\nPending Support Tickets:" << endl;

        while (!temp.empty()) {
            cout << "Ticket ID: "
                << temp.front() << endl;

            temp.pop();
        }
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return tickets.empty();
    }
};

// Main Function
int main() {

    CustomerSupport cs;

    int choice;
    int ticket_id;

    do {

        cout << "\n===== CUSTOMER SUPPORT SYSTEM =====" << endl;
        cout << "1. Add New Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Check Next Ticket" << endl;
        cout << "4. Display Pending Tickets" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter 4-Digit Ticket ID: ";
            cin >> ticket_id;

            cs.enqueue(ticket_id);
            break;

        case 2:
            cs.dequeue();
            break;

        case 3:
            cs.front();
            break;

        case 4:
            cs.display();
            break;

        case 5:
            cout << "Thank You! Program Exited." << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 5);

    return 0;
}
