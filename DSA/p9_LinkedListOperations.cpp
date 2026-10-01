// p9: Write a menu driven program to implement following operations
// on the singly linked list.
// (a) Insert a node at the front of the linked list.
// (b) Insert a node at the end of the linked list.
// (c) Insert a node such that linked list is in ascending order.
// (d) Delete the first node of the linked list.
// (e) Delete a node with a given value.
// (f) Delete a node after specified position.

#include <iostream>
#include <memory>
#include <print>

struct Node
{
    int data;
    std::unique_ptr<Node> next;
};

class List
{
    std::unique_ptr<Node> head;

public:
    void InsertFront(int value)
    {
        head = std::make_unique<Node>(value, std::move(head));
    }

    void InsertEnd(int value)
    {
        auto node = std::make_unique<Node>(value);

        if (!head)
        {
            head = std::move(node);
            return;
        }

        Node *temp = head.get();

        while (temp->next)
            temp = temp->next.get();

        temp->next = std::move(node);
    }

    void InsertSorted(int value)
    {
        if (!head || value < head->data)
        {
            InsertFront(value);
            return;
        }

        Node *temp = head.get();

        while (temp->next && temp->next->data < value)
            temp = temp->next.get();

        auto node = std::make_unique<Node>(value, std::move(temp->next));
        temp->next = std::move(node);
    }

    void DeleteFront()
    {
        if (!head)
        {
            std::println("List is empty");
            return;
        }

        head = std::move(head->next);
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

        Node *temp = head.get();

        while (temp->next && temp->next->data != value)
            temp = temp->next.get();

        if (!temp->next)
        {
            std::println("Value not found");
            return;
        }

        temp->next = std::move(temp->next->next);
    }

    void DeleteAfter(int pos)
    {
        Node *temp = head.get();

        for (int i = 1; temp && i < pos; ++i)
            temp = temp->next.get();

        if (!temp || !temp->next)
        {
            std::println("Invalid position");
            return;
        }

        temp->next = std::move(temp->next->next);
    }

    void Display()
    {
        if (!head)
        {
            std::println("List is empty");
            return;
        }

        for (Node *temp = head.get(); temp; temp = temp->next.get())
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