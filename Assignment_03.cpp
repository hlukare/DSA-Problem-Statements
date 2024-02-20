/* Problem Statement : String Operations: Write a menu driven C++ program with a class for String. Write functions
            1. To determine the frequency of occurrence of a particular character in the string.
            2. Extract a new string from original string by accepting starting position and length
            3. To accept any character and return the string with by removing all occurrences of a character accepted
            4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of same size that of x
            5. To check whether given string is palindrome or not
*/
#include <iostream>
#include <string>
using namespace std;

class String 
{
public:
    string str;

    void setString() 
    {
        cout<< "Please enter 'a' as dummy letter to work properly"<<endl;
        cout << "Please enter a string: ";
        cin.ignore(); 
        getline(cin, str);
    }

    void frequency() 
    {
        char check;
        cout << "Please enter the character you want to check: ";
        cin >> check;
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == check) {
                ++count;
            }
        }
        cout << "Number of " << check << " = " << count << endl;
    }

    void extract() 
    {
        int start, length;
        cout << "Please enter the starting position: ";
        cin >> start;
        cout << "Please enter the length: ";
        cin >> length;
        string string1 = str.substr(start, length);
        cout << "The extracted string is: " << string1 << endl;
    }

    void remove1() 
    {
        char check;
        cout << "Please enter the character you want to remove: ";
        cin >> check;
        string string1 = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != check) {
                string1 += str[i];
            }
        }
        cout << "The string with " << check << " removed is: " << string1 << endl;
    }

    void replace() 
    {
        string oldStr, newStr;
        cout << "Please enter the substring you want to replace: ";
        cin.ignore();
        getline(cin, oldStr);
        cout << "Please enter the new string to replace with: ";
        getline(cin, newStr);
        size_t pos = str.find(oldStr);
        if (pos != string::npos) {
            str.replace(pos, oldStr.length(), newStr);
            cout << "String after replacement: " << str << endl;
        } else {
            cout << "Substring not found in the string." << endl;
        }
    }

    void palindrome() 
    {   
        string lowercaseStr = str;
        for (int i = 0; i < lowercaseStr.length(); i++) {
            lowercaseStr[i] = tolower(lowercaseStr[i]);
        }
        bool palindrome1 = true;
        for (int i = 0; i < lowercaseStr.length() / 2; i++) {
            if (lowercaseStr[i] != lowercaseStr[lowercaseStr.length() - i - 1]) {
                palindrome1 = false;
                break;
            }
        }
        if (palindrome1) {
            cout << "The string is a palindrome" << endl;
        } else {
            cout << "The string is not a palindrome" << endl;
        }
    }
};

int main() {
    int choice;
    String obj;
    obj.setString();

    do {
        cout << "Please enter your choice:\n"
            << "1. To check frequency\n"
            << "2. To extract a new string\n"
            << "3. To remove all occurrences of a character\n"
            << "4. To make replacement of a substring\n"
            << "5. To check whether the string is a palindrome or not\n"
            << "6. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                obj.frequency();
                break;

            case 2:
                obj.extract();
                break;

            case 3:
                obj.remove1();
                break;

            case 4:
                obj.replace();
                break;

            case 5:
                obj.palindrome();
                break;

            case 6:
                cout << "Program terminated successfully!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
