
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Package Structure
struct Package {
    int packageID;
    string address;
    int startTime;
    int endTime;
};

// Logistics Delivery System
class DeliveryQueue {
private:
    queue<Package> packages;

public:

    // 1. Enqueue: Add New Package
    void enqueue(int id, string address, int start, int end) {

        Package p;

        p.packageID = id;
        p.address = address;
        p.startTime = start;
        p.endTime = end;

        packages.push(p);

        cout << "Package added successfully!" << endl;
    }

    // 2. Dequeue: Deliver Front Package
    void dequeue(int currentTime) {

        if (packages.empty()) {
            cout << "No Packages Available!" << endl;
            return;
        }

        Package p = packages.front();

        if (currentTime >= p.startTime &&
            currentTime <= p.endTime) {

            cout << "\nPackage ID: "
                << p.packageID << endl;

            cout << "Address: "
                << p.address << endl;

            cout << "Package Delivered Successfully!" << endl;

            packages.pop();
        }
        else {
            cout << "Package cannot be delivered now!" << endl;
        }
    }

    // 3. Front: Show Next Package
    void front() {

        if (packages.empty()) {
            cout << "No Packages Available!" << endl;
            return;
        }

        Package p = packages.front();

        cout << "\nNext Package Details:" << endl;
        cout << "Package ID: " << p.packageID << endl;
        cout << "Address: " << p.address << endl;
        cout << "Start Time: " << p.startTime << endl;
        cout << "End Time: " << p.endTime << endl;
    }

    // 4. Display All Packages
    void display() {

        if (packages.empty()) {
            cout << "Delivery Queue is Empty!" << endl;
            return;
        }

        queue<Package> temp = packages;

        cout << "\n===== PENDING PACKAGES =====" << endl;

        while (!temp.empty()) {

            Package p = temp.front();

            cout << "\nPackage ID: "
                << p.packageID << endl;

            cout << "Address: "
                << p.address << endl;

            cout << "Start Time: "
                << p.startTime << endl;

            cout << "End Time: "
                << p.endTime << endl;

            temp.pop();
        }
    }

    // 5. Time To Deliver
    void timeToDeliver(int currentTime) {

        if (packages.empty()) {
            cout << "No Packages Available!" << endl;
            return;
        }

        // Check expired packages
        while (!packages.empty()) {

            Package p = packages.front();

            if (currentTime > p.endTime) {

                cout << "\nPackage ID "
                    << p.packageID
                    << " has EXPIRED!" << endl;

                packages.pop();
            }
            else if (currentTime < p.startTime) {

                cout << "\nPackage ID: "
                    << p.packageID << endl;

                cout << "Delivery is not started yet." << endl;

                cout << "Delivery can start at: "
                    << p.startTime << endl;

                return;
            }
            else {

                cout << "\nPackage ID: "
                    << p.packageID << endl;

                cout << "Package can be delivered now!" << endl;

                return;
            }
        }

        cout << "\nNo valid packages remaining!" << endl;
    }

    // Check Empty
    bool isEmpty() {
        return packages.empty();
    }
};

// Main Function
int main() {

    DeliveryQueue dq;

    int choice;
    int id, start, end, currentTime;
    string address;

    do {

        cout << "\n===== LOGISTICS DELIVERY SYSTEM =====" << endl;

        cout << "1. Add New Package" << endl;
        cout << "2. Deliver Package" << endl;
        cout << "3. Check Next Package" << endl;
        cout << "4. Display All Packages" << endl;
        cout << "5. Check Time To Deliver" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Package ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Delivery Address: ";
            getline(cin, address);

            cout << "Enter Start Time (0-23): ";
            cin >> start;

            cout << "Enter End Time (0-23): ";
            cin >> end;

            if (start < 0 || start > 23 ||
                end < 0 || end > 23 ||
                start > end) {

                cout << "Invalid Delivery Time Window!" << endl;
            }
            else {
                dq.enqueue(id, address, start, end);
            }

            break;

        case 2:

            cout << "Enter Current Time (0-23): ";
            cin >> currentTime;

            if (currentTime < 0 || currentTime > 23) {
                cout << "Invalid Current Time!" << endl;
            }
            else {
                dq.dequeue(currentTime);
            }

            break;

        case 3:

            dq.front();
            break;

        case 4:

            dq.display();
            break;

        case 5:

            cout << "Enter Current Time (0-23): ";
            cin >> currentTime;

            if (currentTime < 0 || currentTime > 23) {
                cout << "Invalid Current Time!" << endl;
            }
            else {
                dq.timeToDeliver(currentTime);
            }

            break;

        case 6:

            cout << "Logistics System Closed!" << endl;
            break;

        default:

            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 6);

    return 0;
}
