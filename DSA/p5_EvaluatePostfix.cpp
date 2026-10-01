// p5: Write a program to evaluate a postfix expression
// using a stack.
#include <print>
#include <string>

class Stack
{
    int arr[100];
    int top = -1;

public:
    void Push(int value)
    {
        arr[++top] = value;
    }

    int Pop()
    {
        return arr[top--];
    }
};

int main()
{
    std::string postfix = "23*54*+9-";
    Stack st;

    for (char ch : postfix)
    {
        if (ch >= '0' && ch <= '9')
        {
            st.Push(ch - '0');
        }
        else
        {
            int b = st.Pop();
            int a = st.Pop();

            if (ch == '+')
                st.Push(a + b);
            else if (ch == '-')
                st.Push(a - b);
            else if (ch == '*')
                st.Push(a * b);
            else if (ch == '/')
                st.Push(a / b);
        }
    }

    std::println("Postfix: {}", postfix);
    std::println("Result: {}", st.Pop());

    return 0;
}

/*
Output:

Postfix: 23*54*+9-
Result: 17
*/