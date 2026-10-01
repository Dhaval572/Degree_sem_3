// p1: Write a program to perform addition, 
// subtraction, and multiplication of matrices using arrays.
#include <print>

void CallByValue(int a[[maybe_unused]])
{
    a++;
}

void CallByRef(int &a)
{
    a++;
}

int main()
{
    int a = 10;
    CallByValue(a);
    std::println("A = {} ( after Call By Value )", a);

    CallByRef(a);
    std::println("A = {} ( after Call By Reference )", a);
    
    return 0;
}

/*
Output: 

A = 10 ( after Call By Value )
A = 11 ( after Call By Reference )
*/