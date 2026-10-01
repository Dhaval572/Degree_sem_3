// p10: Write a program to implement stack using linked list.
#include <memory>
#include <print>

class Stack
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> top;

  public:
    void Push(int value)
    {
        top = std::make_unique<Node>(value, std::move(top));
    }

    void Pop()
    {
        if (!top)
        {
            std::println("Stack Underflow");
            return;
        }

        top = std::move(top->next);
    }

    void Peek()
    {
        if (!top)
        {
            std::println("Stack is empty");
            return;
        }

        std::println("Top = {}", top->data);
    }

    void Display()
    {
        if (!top)
        {
            std::println("Stack is empty");
            return;
        }

        for (Node *node = top.get(); node; node = node->next.get())
        {
            std::print("{} ", node->data);
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

    return 0;
}

/*
Output:

Stack:
30 20 10
Top = 30
After Pop:
20 10
*/
