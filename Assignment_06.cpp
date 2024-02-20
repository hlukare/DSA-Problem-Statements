#include <iostream>
#include <ctime>
using namespace std;

struct Node 
{
    string name;
    string birthday;
    Node* next;
};

class Stu_list 
{
private:
    Node* head;

public:
    Stu_list() : head(nullptr) {}

    void insert0() 
    {
        Node* newNode = new Node();
        cout << "Enter student name: ";
        cin >> newNode->name;
        cout << "Enter student birthday (DD/MM): ";
        cin >> newNode->birthday;
        newNode->next = head;
        head = newNode;
        cout << "Student added successfully!\n";
    }

    void delete0() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        string name;
        cout << "Enter the name of the student to delete: ";
        cin >> name;

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->name != name) 
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) 
        {
            if (prev != nullptr) 
            {
                prev->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
            delete current;
            cout << "Student deleted successfully!\n";
        } 
        else 
        {
            cout << "Student not found.\n";
        }
    }

    void displayBirthday() 
    {
        time_t now = time(0);
        tm* today = localtime(&now);
        string todayDate = to_string(today->tm_mday) + "/" + to_string(today->tm_mon + 1);

        Node* current = head;
        while (current != nullptr) 
        {
            if (current->birthday == todayDate) 
            {
                cout << "Happy Birthday, " << current->name << "!\n";
            }
            current = current->next;
        }
    }

    void display0() 
    {
        Node* current = head;
        if (current == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "Student List:\n";
        while (current != nullptr) 
        {
            cout << "Name: " << current->name << ", Birthday: " << current->birthday << endl;
            current = current->next;
        }
    }
};

int main() 
{
    Stu_list obj;
    int choice;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Insert new student\n";
        cout << "2. Delete a student entry\n";
        cout << "3. Display birthday message for today\n";
        cout << "4. Display list of students with birthdays\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                obj.insert0();
                break;
            case 2:
                obj.delete0();
                break;
            case 3:
                obj.displayBirthday();
                break;
            case 4:
                obj.display0();
                break;
            case 5:
                cout << "Program terminated.\n";
                break;
        }
    } 
    while (choice != 5);

    return 0;
}
