// p4: Write a program to convert an infix expression to
// postfix using a stack.
#include <print>
#include <string>

class Stack
{
    char arr[100];
    int top = -1;

public:
    void Push(char value)
    {
        arr[++top] = value;
    }

    char Pop()
    {
        return arr[top--];
    }

    char Peek()
    {
        return arr[top];
    }

    bool IsEmpty()
    {
        return top == -1;
    }
};

int Priority(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

int main()
{
    std::string infix = "A+B*C";
    std::string postfix;

    Stack st;

    for (char ch : infix)
    {
        if (std::isalnum(ch))
        {
            postfix += ch;
        }
        else
        {
            while (!st.IsEmpty() && Priority(st.Peek()) >= Priority(ch))
            {
                postfix += st.Pop();
            }

            st.Push(ch);
        }
    }

    while (!st.IsEmpty())
    {
        postfix += st.Pop();
    }

    std::println("Infix: {}", infix);
    std::println("Postfix: {}", postfix);
}

/*
Output: 

Infix: A+B*C
Postfix: ABC*+
*/