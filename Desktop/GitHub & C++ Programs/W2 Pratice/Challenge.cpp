#include <iostream>

using namespace std;

// Add Node
struct Node
{
    int Number;
    Node* next;
};

// Functions
int NumberofNodes = 0;
int Challenge = 1;

Node *InsertAtEnd (Node* head, int value) {
    Node *ptr = new Node;
    ptr = head;

    // Shifts all the way to NULL
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    // Insert value at the NULL postiton
    Node* Destination = new Node;
    Destination->Number = value;
    Destination->next = nullptr;

    ptr->next = Destination;
    NumberofNodes++;
    return ptr;
}

Node *InsertAtMiddle (Node* head, int value) {
    Node *ptr = new Node;
    ptr = head;

    // Insert the value at the middle
    Node* Destination = new Node;
    Destination->Number = value;
    Destination->next = nullptr;

    // Making sure the preious values are linked together
    while (--NumberofNodes > 1)
    {
        ptr = ptr->next;
    }
    
    Destination->next = ptr->next;
    ptr->next = Destination;

    NumberofNodes++;
    return ptr;
}

Node *InsertAtFront (Node* head, int value) {
    Node *ptr = new Node;
    ptr->Number = value;
    ptr->next = head;
    NumberofNodes++;
    return ptr;
}

Node *RemoveAtEnd (Node* head) {
    Node *ptr = new Node;
    ptr = head;

    // Shifts all the way to NULL
    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }

    // Removes Value at Destination
    Node* Destination = new Node;
    Destination = ptr->next;
    delete Destination;
    ptr->next = nullptr;

    NumberofNodes--;
    return ptr;
}

Node *RemoveAtMiddle (Node* head) {
    Node *ptr = new Node;
    ptr = head;

    int mid = NumberofNodes;

    mid--;
    while (mid > 1)
    {
        ptr = ptr->next;
        mid--;
    }
    
    // Removes Value at Destination
    Node* Destination = new Node;
    Destination = ptr->next;
    ptr->next = Destination->next;
    delete Destination;

    NumberofNodes--;
    return ptr;
}

Node *RemoveAtFront (Node* head) {
    Node *ptr = new Node;
    ptr = head;

    head = head->next;
    delete ptr;

    NumberofNodes--;
    return head;
}

int Search(Node *head) {
    int Searched;
    cout << "(Challenge "<< Challenge << ") What value to search: ";
    cin >> Searched;

    // Find a value that matches
    int pos = 0;
    Node *ptr = new Node;
    ptr = head;

    while (ptr != nullptr)
    {
        pos++;
        if (ptr->Number == Searched)
        {
            return pos;
        }
        ptr = ptr->next;  
    }  
}

void Print(Node* head) {
    cout << "(Challenge " << Challenge << ") Data in Node: ";
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->Number << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Make the head NULL (to create a headnode)
    Node *head = new Node;
    head = nullptr;

    // Challenge 1
    head = InsertAtFront(head, 3);
    // Print(head);
    Challenge++;

    // Challenge 2
    head = InsertAtEnd(head, 7);
    // Print(head);
    Challenge++;

    // Challenge 3
    head = InsertAtMiddle(head, 6);
    // Print(head);
    Challenge++;

    // Challenge 4
    head = RemoveAtFront(head);
    // Print(head);
    Challenge++;

    // Challenge 5
    head = RemoveAtEnd(head);
    // Print(head);
    Challenge++;

    // Challenge 6
    // Out of Numbers, need to create new ones
    head = nullptr;
    head = InsertAtFront(head, 9);
    head = InsertAtEnd(head, 4);
    head = InsertAtMiddle(head, 1);
    Print(head);
    cout << "(This is Before Executing Function)" << endl;

    RemoveAtMiddle(head);
    // Print(head);
    Challenge++;

    // Challenge 7
    Print(head);
    Challenge++;

    // Challenge 8
    // I don't know how to code this
    Challenge++;

    // Challenge 9
    int result;
    result = Search(head);
    cout << "Searched Value is in postiton " << result << endl;
    Challenge++;
}
