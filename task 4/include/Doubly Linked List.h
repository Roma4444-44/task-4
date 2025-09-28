#ifndef DOUBLY LINKED LIST_H
#define DOUBLY LINKED LIST_H
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insertLeft(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void insertRight(int value)
    {
        Node* newNode = new Node(value);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    void insertAtPosition(int position, int value)
    {
        if (position < 1 || position > size + 1)
        {
            cout << "❌ Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            insertLeft(value);
        }
        else if (position == size + 1)
        {
            insertRight(value);
        }
        else
        {
            Node* newNode = new Node(value);
            Node* temp = head;
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
        }
    }
    void removeLeft()
    {
        if (head == nullptr)
        {
            cout << "❌ List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }
    void removeRight()
    {
        if (tail == nullptr)
        {
            cout << "❌ List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }
    void removeAtPosition(int position)
    {
        if (position < 1 || position > size)
        {
            cout << "❌ Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            removeLeft();
        }
        else if (position == size)
        {
            removeRight();
        }
        else
        {
            Node* temp = head;
            for (int i = 1; i < position; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
    }
    void search(int value)
    {
        Node* temp = head;
        int pos = 1;
        bool found = false;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << " Value " << value << " found at position " << pos << endl;
                found = true;
            }
            temp = temp->next;
            pos++;
        }
        if (!found)
        {
            cout << " Value " << value << " not found in the list!" << endl;
        }
    }
    void editAtPosition(int position, int newValue)
    {
        if (position < 1 || position > size)
        {
            cout << " Invalid position!" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position; i++)
        {
            temp = temp->next;
        }
        temp->data = newValue;
        cout << "Value updated at position " << position << endl;
    }
    void print()
    {
        if (head == nullptr)
        {
            cout << " List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << " List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            removeLeft();
        }
    }
};
#endif
