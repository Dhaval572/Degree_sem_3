// p2: Implement a stack using arrays and perform the
// following operations: Push, Pop, Peek, and Display.

#include <print>

class Stack
{
    int arr[5];
    int top = -1;

  public:
    void Push(int value)
    {
        if (top == 4)
        {
            std::println("Stack Overflow");
            return;
        }

        arr[++top] = value;
    }

    void Pop()
    {
        if (top == -1)
        {
            std::println("Stack Underflow");
            return;
        }

        --top;
    }

    void Peek()
    {
        if (top == -1)
        {
            std::println("Stack Underflow");
            return;
        }

        std::println("Top = {}", arr[top]);
    }

    void Display()
    {
        if (top == -1)
        {
            std::println("Stack is empty");
            return;
        }

        for (int i = top; i >= 0; --i)
        {
            std::print("{} ", arr[i]);
        }

        std::println();
    }
};

int main()
{
    Stack st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    std::println("Stack:");
    st.Display();

    st.Peek();

    st.Pop();

    std::println("After Pop:");
    st.Display();
}

/*
Output:

Stack:
30 20 10
Top = 30
After Pop:
20 10
*/