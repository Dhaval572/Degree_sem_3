// p6: Implement the Tower of Hanoi problem using
// recursion.
#include <print>

void Hanoi(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        std::println("Move disk 1 from {} to {}", src, dest);
        return;
    }

    Hanoi(n - 1, src, dest, aux);
    std::println("Move disk {} from {} to {}", n, src, dest);
    Hanoi(n - 1, aux, src, dest);
}

int main()
{
    int n = 3;

    std::println("Number of disks: {}", n);
    Hanoi(n, 'A', 'B', 'C');

    return 0;
}

/*
Output:

Number of disks: 3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/