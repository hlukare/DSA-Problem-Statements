#include <iostream>
using namespace std;

const int MAX_ORDERS = 100;

class CircularQueue 
{
private:
    int front, rear;
    int orders[MAX_ORDERS];

public:
    CircularQueue() 
    {
        front = rear = -1;
    }

    bool isEmpty() 
    {
        return front == -1;
    }

    bool isFull() 
    {
        return (front == 0 && rear == MAX_ORDERS - 1) || (rear == (front - 1) % (MAX_ORDERS - 1));
    }

    void enqueue(int orderNumber) 
    {
        if (isFull()) 
        {
            cout << "Sorry, the pizza parlor is full. Cannot accept more orders.\n";
        } 
        else 
        {
            if (front == -1)
                front = rear = 0;
            else
                rear = (rear + 1) % MAX_ORDERS;

            orders[rear] = orderNumber;
            cout << "Order " << orderNumber << " placed successfully!\n";
        }
    }

    void serveOrder() 
    {
        if (isEmpty()) 
        {
            cout << "No orders to serve. The pizza parlor is empty.\n";
        } 
        else 
        {
            int servedOrder = orders[front];
            cout << "Order " << servedOrder << " served.\n";

            if (front == rear) 
            {
                front = rear = -1;
            } 
            else 
            {
                front = (front + 1) % MAX_ORDERS;
            }
        }
    }
};

int main() 
{
    int M; 
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    CircularQueue pizzaQueue;

    int choice;
    do 
    {
        cout << "\nPizza Parlor Simulation\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                if (pizzaQueue.isFull()) 
                {
                    cout << "Sorry, the pizza parlor is full. Cannot accept more orders.\n";
                } 
                else 
                {
                    int orderNumber;
                    cout << "Enter order number: ";
                    cin >> orderNumber;
                    pizzaQueue.enqueue(orderNumber);
                }
                break;

            case 2:
                pizzaQueue.serveOrder();
                break;

            case 3:
                cout << "Exiting the simulation.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } 
    while (choice != 3);

    return 0;
}
