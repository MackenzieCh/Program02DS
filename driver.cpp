/** Mackenzie Chapman
Program 2
This program asks the user to input the number of elements for a linked list, then it asks for the values
for each position in the linked list. The first position is filled via the insertAtBeginning function, 
then each following iteration will get the values for the middle nodes using the insertAtPosition function.
Finally, once the last node is reached, the insertAtEnd function is utilized to finish the linked list.
COSC 2436 Data Structures
09/29/2024
*/



#include <iostream>
#include "LinkedList.cpp"

using namespace std;


int main()
{
    LinkedList myList;
    int nodeCount;
    char choice;
    int value, position;

    // Get length of linked list
     cout << "Enter the number of elements in the linked list: ";
     cin >> nodeCount;

     if (nodeCount <= 1000)
     {
         // Populate the linked list in sequential order
         for (int i = 0; i < nodeCount; i++)
         {
             if (i == 0)
             {
                 cout << "Enter the value for the position 0: ";
                 cin >> value;
                 myList.insertAtBeginning(value);
             }

             else if (i > 0 && i != nodeCount - 1)
             {
                 position = i;
                 cout << "Enter the value for position " << position << ": ";
                 cin >> value;
                 myList.insertAtPosition(value, position);
             }

             else
             {
                 cout << "Enter the value for the last node: ";
                 cin >> value;
                 myList.insertAtEnd(value);
             }
         }


         cout << "Original List: ";
         myList.printList();
     }

     // Validate list does not exceed 1000
     else
     {
         cout << "Error: Number of elements cannot exceed 1000.";
     }

     //Edit the list
     cout << "\nWould you like to edit the list (y/n)? ";
     cin >> choice;

     while (choice == 'y' || choice == 'Y')
     {
         cout << "Enter the position to edit: ";
         cin >> position;

         cout << "Enter the value: ";
         cin >> value;

         myList.insertAtPosition(value, position);

         cout << "\nWould you like to edit the list (y/n)? ";
         cin >> choice;

     }

     cout << "New List: ";
     myList.printList();

    return 0;
}