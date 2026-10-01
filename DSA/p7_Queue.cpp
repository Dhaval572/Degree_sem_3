// p7: Write a program to implement a queue using arrays
// and perform Enqueue, Dequeue, and Display operations.
#include <print>

class Queue
{
    int arr[5];
    int front = 0;
    int rear = -1;

public:
    void Enqueue(int value)
    {
        if (rear == 4)
        {
            std::println("Queue Overflow");
            return;
        }

        arr[++rear] = value;
    }

    void Dequeue()
    {
        if (front > rear)
        {
            std::println("Queue Underflow");
            return;
        }

        ++front;
    }

    void Display()
    {
        if (front > rear)
        {
            std::println("Queue is empty");
            return;
        }

        for (int i = front; i <= rear; ++i)
        {
            std::print("{} ", arr[i]);
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

    std::println("Queue:");
    q.Display();

    q.Dequeue();

    std::println("After Dequeue:");
    q.Display();

    return 0;
}

/*
Output:

Queue:
10 20 30
After Dequeue:
20 30
*/