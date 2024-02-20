#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Node structure for appointment
struct Node {
    string name;
    int start;
    int end;
    bool booked;
    Node* next;
    Node* prev;

    Node() : name("NULL"), start(0), end(0), next(nullptr), booked(false) {}
    Node(string n, int s, int e, bool book) {
        this->name = n;
        this->start = s;
        this->end = e;
        this->booked = book;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node* head = nullptr;

// Function to display free slots
void displayFreeSlots() {
    Node* current = head;
    cout << "Free Slots:\n";
    while (current != nullptr) {
        if (!current->booked) {
            cout << "Start Time: " << current->start << ", End Time: " << current->end << endl;
        }
        current = current->next;
    }
    cout << endl;
}

// Function to book an appointment randomly
void bookAppointment() {
    string name;
    int startTime;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter start time (in 24-hour format): ";
    cin >> startTime;

    Node* current = head;
    while (current != nullptr) {
        if (current->start == startTime && !current->booked) {
            current->name = name;
            current->booked = true;
            cout << "Appointment booked successfully.\n";
            return;
        }
        current = current->next;
    }
    cout << "Invalid start time or slot already booked. Appointment not scheduled.\n";
}

// Function to cancel an appointment
void cancelAppointment() {
    int startTime;
    cout << "Enter start time of the appointment to cancel: ";
    cin >> startTime;

    Node* current = head;
    while (current != nullptr) {
        if (current->start == startTime && current->booked) {
            current->name = "NULL";
            current->booked = false;
            cout << "Appointment canceled successfully.\n";
            return;
        }
        current = current->next;
    }
    cout << "Invalid start time or appointment not found.\n";
}

// Function to sort the list based on time
void sortList() {
    if (head == nullptr || head->next == nullptr) {
        cout << "List is already sorted or empty.\n";
        return;
    }

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        Node* innerCurrent = current->next;
        while (innerCurrent != nullptr) {
            if (current->start > innerCurrent->start) {
                // Swap nodes
                temp = new Node(current->name, current->start, current->end, current->booked);
                current->name = innerCurrent->name;
                current->start = innerCurrent->start;
                current->end = innerCurrent->end;
                innerCurrent->name = temp->name;
                innerCurrent->start = temp->start;
                innerCurrent->end = temp->end;
            }
            innerCurrent = innerCurrent->next;
        }
        current = current->next;
    }

    cout << "List sorted successfully based on time.\n";
}

// Function to display the linked list
void displayList() {
    Node* current = head;
    cout << "Appointments:\n";
    while (current != nullptr) {
        if (current->booked) {
            cout << "Name: " << current->name << ", Start Time: " << current->start << ", End Time: " << current->end << endl;
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    
    // Initialize time slots
    for (int i = 9; i < 19; ++i) {
        Node* newNode = new Node("", i * 100, (i + 1) * 100, false);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    int choice;
    do {
        cout << "Menu:\n1. Display Free Slots\n2. Book Appointment\n3. Cancel Appointment\n4. Sort List\n5. Display Appointments\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFreeSlots();
                break;

            case 2:
                bookAppointment();
                break;

            case 3:
                cancelAppointment();
                break;

            case 4:
                sortList();
                break;

            case 5:
                displayList();
                break;

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
