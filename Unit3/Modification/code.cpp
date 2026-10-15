#include <iostream>
using namespace std;

struct Node {
    int coachNo;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Add coach at the beginning
void addCoach() {
    Node* newNode = new Node;

    cout << "Enter coach number: ";
    cin >> newNode->coachNo;

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    cout << "Coach added at beginning!\n";
}

// Display forward
void displayForward() {
    if (head == NULL) {
        cout << "Train is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Coaches (Forward): ";

    while (temp != NULL) {
        cout << temp->coachNo << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Display reverse
void displayReverse() {
    if (head == NULL) {
        cout << "Train is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Coaches (Reverse): ";

    while (temp != NULL) {
        cout << temp->coachNo << " ";
        temp = temp->prev;
    }

    cout << endl;
}

// Delete first coach
void deleteFirstCoach() {
    if (head == NULL) {
        cout << "No coach to delete.\n";
        return;
    }

    Node* temp = head;

    cout << "Deleted coach: " << temp->coachNo << endl;

    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

// Search coach
void searchCoach() {
    int number;

    cout << "Enter coach number to search: ";
    cin >> number;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->coachNo == number) {
            cout << "Coach " << number
                 << " found in the train.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Coach not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Train Coach Management System ---\n";
        cout << "1. Add Coach at Beginning\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Reverse\n";
        cout << "4. Delete First Coach\n";
        cout << "5. Search Coach\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCoach();
                break;

            case 2:
                displayForward();
                break;

            case 3:
                displayReverse();
                break;

            case 4:
                deleteFirstCoach();
                break;

            case 5:
                searchCoach();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
