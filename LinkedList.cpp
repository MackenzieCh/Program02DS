#include <iostream>
#include "Node.cpp"

using namespace std;


class LinkedList
{
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the linked list
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

    }

    // Function to insert a node at the end of the linked list
    void insertAtEnd(int value) 
    {
        Node* newNode = new Node(value);

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a node at a specific position in the linked list
    void insertAtPosition(int value, int position) 
    {
        Node* newNode = new Node(value);


        // if inserting at position 0
        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // traverse the list to find node prior to insertion point
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        // validate position
        if (temp == nullptr)
        {
            cout << "Position is out of bounds." << endl;
            delete newNode;
            return;
        }

        // insert new node
        newNode->next = temp->next;
        temp->next = newNode;

    }


    // Function to print the linked list
    void printList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }

};
