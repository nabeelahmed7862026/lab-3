
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class PrinterQueue {
private:
    queue<string> printJobs;

public:

    // 1. Enqueue: Add New Print Job
    void enqueue(string document) {

        printJobs.push(document);

        cout << document
            << " added to print queue successfully!" << endl;
    }

    // 2. Dequeue: Print Document
    void dequeue() {

        if (printJobs.empty()) {
            cout << "No Print Jobs Available!" << endl;
            return;
        }

        cout << "Printing Document: "
            << printJobs.front() << endl;

        printJobs.pop();

        cout << "Document Printed Successfully!" << endl;
    }

    // 3. Front: Check Next Document
    void front() {

        if (printJobs.empty()) {
            cout << "No Print Jobs Available!" << endl;
            return;
        }

        cout << "Next Document to Print: "
            << printJobs.front() << endl;
    }

    // 4. Display All Remaining Print Jobs
    void display() {

        if (printJobs.empty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        queue<string> temp = printJobs;

        cout << "\nRemaining Print Jobs:" << endl;

        while (!temp.empty()) {

            cout << temp.front() << endl;

            temp.pop();
        }
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return printJobs.empty();
    }
};

// Main Function
int main() {

    PrinterQueue printer;

    int choice;
    string document;

    do {

        cout << "\n===== OFFICE PRINTER QUEUE SYSTEM =====" << endl;

        cout << "1. Add New Print Job" << endl;
        cout << "2. Print Document" << endl;
        cout << "3. Check Next Document" << endl;
        cout << "4. Display Remaining Print Jobs" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

        case 1:
            cout << "Enter Document Name: ";
            getline(cin, document);

            printer.enqueue(document);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.front();
            break;

        case 4:
            printer.display();
            break;

        case 5:
            cout << "Printer System Closed Successfully!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 5);

    return 0;
}
