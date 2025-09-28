#include <iostream>
#include <Doubly Linked List.h>
using namespace std;
int main()
{
    DoublyLinkedList dll;
    int choice, value, position;

    do
    {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert Left\n";
        cout << "2. Insert Right\n";
        cout << "3. Insert at Position\n";
        cout << "4. Remove Left\n";
        cout << "5. Remove Right\n";
        cout << "6. Remove at Position\n";
        cout << "7. Search\n";
        cout << "8. Edit at Position\n";
        cout << "9. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dll.insertLeft(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            dll.insertRight(value);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> position >> value;
            dll.insertAtPosition(position, value);
            break;
        case 4:
            dll.removeLeft();
            break;
        case 5:
            dll.removeRight();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            dll.removeAtPosition(position);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            dll.search(value);
            break;
        case 8:
            cout << "Enter position and new value: ";
            cin >> position >> value;
            dll.editAtPosition(position, value);
            break;
        case 9:
            dll.print();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << " Invalid choice!" << endl;
        }
    }
    while (choice != 0);

    return 0;
}

