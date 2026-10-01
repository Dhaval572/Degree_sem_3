// p2: Write a program to perform addition, subtraction, and multiplication of
// matrices using arrays.
#include <array>
#include <print>

using Matrix = std::array<std::array<int, 2>, 2>;

void print(const Matrix &m)
{
    for (const auto &row : m)
    {
        for (int value : row)
        {
            std::print("{} ", value);
        }
        std::println();
    }
}

int main()
{
    Matrix a{{{1, 2}, {3, 4}}};
    Matrix b{{{5, 6}, {7, 8}}};

    Matrix add{}, sub{}, mul{};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            add[i][j] = a[i][j] + b[i][j];
            sub[i][j] = a[i][j] - b[i][j];

            for (int k = 0; k < 2; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    std::println("Addition:");
    print(add);

    std::println("\nSubtraction:");
    print(sub);

    std::println("\nMultiplication:");
    print(mul);
}

/* 
Output:

Addition:
6 8
10 12

Subtraction:
-4 -4
-4 -4

Multiplication:
19 22
43 50
*/