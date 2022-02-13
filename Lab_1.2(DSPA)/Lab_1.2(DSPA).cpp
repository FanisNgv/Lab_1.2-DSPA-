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

bool isfull()
{
    if ((rear+1)%SIZE == front)
        return true;
    else
        return false;
}

void enqueue(int value)
{
    if (isfull())
    {
        std::cout << "Очередь полна" << std::endl;
    }
    else
    {
        if (front == -1) 
            front = 0;
        rear = (rear + 1) % SIZE;
        A[rear] = value;

    }
}

void dequeue()
{
    if (isempty())
    {
        std::cout << "Очередь уже пуста" << std::endl;
    }
    else
    {
        if (front == rear)      //добавили один элемент и удалили
            front = rear = -1;
        else {
            front = (front + 1) % SIZE;
        }

    }
}

void ShowFront()
{
    if (isempty())
    {
        std::cout << "Очередь пуста" << std::endl;
    }
    else
        std::cout << "Первый элемент: " << A[front] << std::endl;
}

void ShowQueue()
{
    if (isempty())
    {
        std::cout << "Очередь пуста" << std::endl;
    }
    else if (front == rear)
    {
        std::cout << A[0] << " " << std::endl;
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % SIZE)
        {
            std::cout << A[i] << " ";

            if ((i + 1)%SIZE == rear)
            {
                std::cout << A[(i + 1)%SIZE] << " ";
            }
        }
        std::cout << std::endl;
            
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    char choice;

    while (true)
    {
        std::cout <<
            "1-добавить новый элемент\n"
            "2-удалить элемент\n"
            "q-выход из цикла\n";

        while ((!(std::cin >> choice) || (std::cin.peek() != '\n')))
        {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "ошибка!" << std::endl;
        }
        if (choice == '1')
        {
            enqueue(rand() % 101);
        }
        else if (choice == '2')
        {
            dequeue();
        }
        else if (choice == 'q')
        {
            break;
        }
        else
        {
            std::cout << "Введите символ из предоставленного списка!" << std::endl;
        }
        ShowQueue();
    }
}

