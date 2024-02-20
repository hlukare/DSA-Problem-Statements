/* Problem Statement : Polynomial operations: Write a menu driven C++ program with class for single variable 
					 	polynomial and write functions to perform following polynomial operations using arrays 
						1. Read polynomial 
						2. Display polynomial 
						3. Add two polynomials

*/
#include <iostream>
#include <cmath>
using namespace std;

struct poly {
    int coeff;
    int expo;
};

int getdata(struct poly[], int t1);
void display(struct poly[], int term);
void addition(struct poly[], struct poly[], struct poly[], int t1, int t2);

int main() {
    int t1, t2;
    struct poly p1[10];
    struct poly p2[10];
    struct poly result[10];

    cout << "Enter the total terms in polynomial 1: ";
    cin >> t1;
    t1 = getdata(p1, t1);

    cout << "Enter the total terms in polynomial 2: ";
    cin >> t2;
    t2 = getdata(p2, t2);

    cout << "Polynomial 1 is: ";
    display(p1, t1);

    cout << "Polynomial 2 is: ";
    display(p2, t2);

    addition(p1, p2, result, t1, t2);

    cout << "Resultant polynomial is: ";
    display(result, t1 + t2);
    
    //double evaluatedResult = evaluate(result, t1 + t2, x);
    //cout << "Result of polynomial evaluation at x = " << x << " is: " << evaluatedResult << endl;


    return 0;
}
/*
double evaluate(struct poly p[], int term, double x) {
    double result = 0.0;
    for (int i = 0; i < term; i++) {
        result += p[i].coeff * pow(x, p[i].expo);
    }
    return result;
}
*/
int getdata(struct poly p[], int t1) {
    cout << "Enter the Coefficient and Exponent:\n";
    for (int i = 0; i < t1; i++) {
        cout << "Enter the Coefficient " << i + 1 << ": ";
        cin >> p[i].coeff;
        cout << "Enter the Exponent " << i + 1 << ": ";
        cin >> p[i].expo;
    }
    return t1;
}

void display(struct poly p[], int term) {
    for (int i = 0; i < term - 1; i++) {
        cout << p[i].coeff << "(x^" << p[i].expo << ") + ";
    }
    cout << p[term - 1].coeff << "(x^" << p[term - 1].expo << ")\n";
}

void addition(struct poly p1[], struct poly p2[], struct poly result[], int t1, int t2) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            result[k].expo = p1[i].expo;
            result[k].coeff = p1[i].coeff;
            k++;
            i++;
        } else {
            result[k].expo = p2[j].expo;
            result[k].coeff = p2[j].coeff;
            k++;
            j++;
        }
    }

    while (i < t1) {
        result[k].expo = p1[i].expo;
        result[k].coeff = p1[i].coeff;
        k++;
        i++;
    }

    while (j < t2) {
        result[k].expo = p2[j].expo;
        result[k].coeff = p2[j].coeff;
        k++;
        j++;
    }
}
