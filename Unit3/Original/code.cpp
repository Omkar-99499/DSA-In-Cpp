#include <iostream>
using namespace std;

struct Node {
    int coachNo;
    Node* next;
};

Node* head = NULL;

void addCoach() {
    Node* n = new Node;
    cout << "Enter Coach Number: ";
    cin >> n->coachNo;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
    cout << "Coach Added!\n";
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coachNo << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void removeCoach() {
    if (head == NULL)
        cout << "No Coaches!\n";
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First Coach Removed!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Coach";
        cout << "\n2. Display Coaches";
        cout << "\n3. Remove First Coach";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCoach(); break;
            case 2: display(); break;
            case 3: removeCoach(); break;
            case 4: cout << "Program Ended!\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
