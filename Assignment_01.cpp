/*  Problem Statement : Set operations: Write a menu driven C++ program to store sets for students' names
                        participating in different events in Equinox such as Coding contest, Project competition,
                        Paper Presentation, MasterMind etc. 
                        1. Find out participants who have participated in Coding and Project both 
                        2. Find out participants who have participated in Coding or Project competition or both or Mastermind 
                        3. Find out participants who have participated in Coding but not in Master mind 
                        4. Find out participants who have participated in all events
    
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int num, i;
    string name[100];
    string div[100];
    string comp[100];

    void coding() {
        cout << "Enter number of students : \n";
        cin >> num;
        for (i = 0; i < num; i++) {
            cout << "Enter Competition name (eg. coding/paper/project/mastermind) : \n";
            cin >> comp[i];
            cout << "Enter student's name : \n";
            cin >> name[i];
            cout << "Enter student's division : \n";
            cin >> div[i];
        }
    }

    void one() {
        for (i = 0; i < num; i++) {
            if (comp[i] == "coding" && comp[i] == "project") {
                cout << "student's name is : " << name[i] << endl;
                cout << "student's division is : " << div[i] << endl;
            }
        }
        cout << "\n";
    }

    void two() {
        for (i = 0; i < num; i++) {
            if (comp[i] == "coding" || comp[i] == "project" || comp[i] == "mastermind") {
                cout << "student's name is : " << name[i] << endl;
                cout << "student's division is : " << div[i] << endl;
            }
        }
        cout << "\n";
    }

    void three() {
        for (i = 0; i < num; i++) {
            if (comp[i] == "coding" && comp[i] != "mastermind") {
                cout << "student's name is : " << name[i] << endl;
                cout << "student's division is : " << div[i] << endl;
            }
        }
        cout << "\n";
    }

    void four() {
        for (i = 0; i < num; i++) {
            if (comp[i] == "coding" && comp[i] == "project" && comp[i] == "paper" && comp[i] == "mastermind") {
                cout << "student's name is : " << name[i] << endl;
                cout << "student's division is : " << div[i] << endl;
            }
        }
        cout << "\n";
    }
};

int main() {
    int ch;
    Student obj;
    obj.coding();
    do {
        cout << "Please select your choice:\n"
            << "1. Participants participated in Coding and Project both\n"
            << "2. Participants participated in Coding or Project or both or MasterMind\n"
            << "3. Participants participated in Coding but not in Mastermind\n"
            << "4. Participants participated in all events\n"
            << "5. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                obj.one();
                break;
            }

            case 2: {
                obj.two();
                break;
            }

            case 3: {
                obj.three();
                break;
            }

            case 4: {
                obj.four();
                break;
            }
        }
    } while (ch != 5);
    return 0;
}
