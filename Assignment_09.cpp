#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;

string dataProcess(const string& str) 
{
    string string0;

    for (char ch : str) 
    {
        if (isalnum(ch)) 
        {
            string0 += tolower(ch);
        }
    }

    return string0;
}

void reversed(const string& originalStr) 
{
    stack<char> charStack;

    for (char ch : originalStr) 
    {
        charStack.push(ch);
    }
    cout << "Original String: " << originalStr << endl;

    cout << "Reversed String : ";
    while (!charStack.empty()) 
    {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl;
}

bool isPalindrome(const string& str) 
{
    string new_String = dataProcess(str);
    stack<char> charStack;

    for (char ch : new_String) 
    {
        charStack.push(ch);
    }

    while (!charStack.empty()) 
    {
        if (charStack.top() != new_String.front()) 
        {
            return false;
        }

        charStack.pop();
        new_String.erase(0, 1);
    }

    return true;
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    reversed(str);
    if (isPalindrome(str)) 
    {
        cout << "The given string is a palindrome." << endl;
    } 
    else 
    {
        cout << "The given string is not a palindrome." << endl;
    }

    return 0;
}
