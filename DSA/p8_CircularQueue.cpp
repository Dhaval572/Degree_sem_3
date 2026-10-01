// p8: Implement a circular queue using arrays and
// demonstrate its operations.
#include <print>

class Queue
{
    int arr[5];
    int front = 0;
    int rear = -1;
    int count = 0;

public:
    void Enqueue(int value)
    {
        if (count == 5)
        {
            std::println("Queue Overflow");
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = value;
        ++count;
    }

    void Dequeue()
    {
        if (count == 0)
        {
            std::println("Queue Underflow");
            return;
        }

        front = (front + 1) % 5;
        --count;
    }

    void Display()
    {
        if (count == 0)
        {
            std::println("Queue is empty");
            return;
        }

        for (int i = 0; i < count; ++i)
        {
            std::print("{} ", arr[(front + i) % 5]);
        }

        std::println();
    }
};

int main()
{
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    std::println("Queue:");
    q.Display();

    q.Dequeue();
    q.Dequeue();

    q.Enqueue(60);
    q.Enqueue(70);

    std::println("After Dequeue and Enqueue:");
    q.Display();

    return 0;
}

/*
Output:

Queue:
10 20 30 40 50
After Dequeue and Enqueue:
30 40 50 60 70
*/