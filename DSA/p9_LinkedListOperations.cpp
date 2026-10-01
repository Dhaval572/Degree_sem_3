// p9: Write a menu driven program to implement following operations
// on the singly linked list.
// (a) Insert a node at the front of the linked list.
// (b) Insert a node at the end of the linked list.
// (c) Insert a node such that linked list is in ascending order.
// (d) Delete the first node of the linked list.
// (e) Delete a node with a given value.
// (f) Delete a node after specified position.

#include <iostream>
#include <print>

struct Node
{
    int data;
    Node *next;
};

class List
{
    Node *head = nullptr;

public:
    void InsertFront(int value)
    {
        head = new Node{value, head};
    }

    void InsertEnd(int value)
    {
        Node *node = new Node{value, nullptr};

        if (!head)
        {
            head = node;
            return;
        }

        Node *temp = head;

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    void InsertSorted(int value)
    {
        if (!head || value < head->data)
        {
            InsertFront(value);
            return;
        }

        Node *temp = head;

        while (temp->next && temp->next->data < value)
            temp = temp->next;

        temp->next = new Node{value, temp->next};
    }

    void DeleteFront()
    {
        if (!head)
        {
            std::println("List is empty");
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteValue(int value)
    {
        if (!head)
        {
            std::println("List is empty");
            return;
        }

        if (head->data == value)
        {
            DeleteFront();
            return;
        }

        Node *temp = head;

        while (temp->next && temp->next->data != value)
            temp = temp->next;

        if (!temp->next)
        {
            std::println("Value not found");
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void DeleteAfter(int pos)
    {
        Node *temp = head;

        for (int i = 1; temp && i < pos; ++i)
            temp = temp->next;

        if (!temp || !temp->next)
        {
            std::println("Invalid position");
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void Display()
    {
        if (!head)
        {
            std::println("List is empty");
            return;
        }

        for (Node *temp = head; temp; temp = temp->next)
            std::print("{} ", temp->data);

        std::println();
    }
};

int main()
{
    List list;
    int choice, value, pos;

    do
    {
        std::println("\n1. Insert Front");
        std::println("2. Insert End");
        std::println("3. Insert in Ascending Order");
        std::println("4. Delete First");
        std::println("5. Delete Value");
        std::println("6. Delete After Position");
        std::println("7. Display");
        std::println("0. Exit");

        std::print("Enter choice: ");
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::print("Enter value: ");
            std::cin >> value;
            list.InsertFront(value);
            break;

        case 2:
            std::print("Enter value: ");
            std::cin >> value;
            list.InsertEnd(value);
            break;

        case 3:
            std::print("Enter value: ");
            std::cin >> value;
            list.InsertSorted(value);
            break;

        case 4:
            list.DeleteFront();
            break;

        case 5:
            std::print("Enter value: ");
            std::cin >> value;
            list.DeleteValue(value);
            break;

        case 6:
            std::print("Enter position: ");
            std::cin >> pos;
            list.DeleteAfter(pos);
            break;

        case 7:
            list.Display();
            break;

        case 0:
            break;

        default:
            std::println("Invalid choice");
        }
    } while (choice != 0);

    return 0;
}

/*
Output:

1. Insert Front
2. Insert End
3. Insert in Ascending Order
4. Delete First
5. Delete Value
6. Delete After Position
7. Display
0. Exit

Enter choice: 1
Enter value: 20

Enter choice: 2
Enter value: 40

Enter choice: 1
Enter value: 10

Enter choice: 7
10 20 40

Enter choice: 5
Enter value: 20

Enter choice: 7
10 40
*/