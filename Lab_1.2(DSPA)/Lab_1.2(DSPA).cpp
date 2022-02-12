#include <iostream>

#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        std::cout << "Queue is already full" << std::endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        A[rear] = value;
    }
}

void dequeue()
{
    if (isempty())
    {
        std::cout << "Queue is already empty" << std::endl;
    }
    else
    {
        if (front == rear) // случай, когда оба равны нулю (всего один элемент)
            front = rear = -1;
        else
            front++;
    }
}

void ShowFront()
{
    if (isempty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
        std::cout << "First element: " << A[front] << std::endl;
}

void ShowQueue()
{
    if (isempty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            std::cout << A[i] << std::endl;
        }
    }
}

int main()
{
    enqueue(16);
    isempty();
    enqueue(12);
    ShowFront();
    ShowQueue();
    enqueue(4);
    enqueue(46);
    enqueue(2257);
    enqueue(534);
    ShowQueue();

}

