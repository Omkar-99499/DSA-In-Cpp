#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

Node* createNode(int value)
{
    Node* temp = new Node;

    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->lthread = true;
    temp->rthread = true;

    return temp;
}

Node* insert(Node* root, int value)
{
    Node* ptr = root;
    Node* parent = nullptr;

    while (ptr != nullptr)
    {
        if (value == ptr->data)
            return root;

        parent = ptr;

        if (value < ptr->data)
        {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* temp = createNode(value);

    if (parent == nullptr)
    {
        root = temp;
    }
    else if (value < parent->data)
    {
        temp->left = parent->left;
        temp->right = parent;

        parent->lthread = false;
        parent->left = temp;
    }
    else
    {
        temp->left = parent;
        temp->right = parent->right;

        parent->rthread = false;
        parent->right = temp;
    }

    return root;
}

// Find the inorder predecessor
Node* predecessor(Node* ptr)
{
    if (ptr->lthread)
        return ptr->left;

    ptr = ptr->left;

    while (!ptr->rthread)
        ptr = ptr->right;

    return ptr;
}

// Find the inorder successor
Node* successor(Node* ptr)
{
    if (ptr->rthread)
        return ptr->right;

    ptr = ptr->right;

    while (!ptr->lthread)
        ptr = ptr->left;

    return ptr;
}

// Display predecessor and successor threads
void displayThreads(Node* root)
{
    Node* ptr = root;

    while (ptr != nullptr && !ptr->lthread)
        ptr = ptr->left;

    cout << "\nPredecessor and Successor Threads:\n";

    while (ptr != nullptr)
    {
        cout << "Node: " << ptr->data;

        if (ptr->lthread)
        {
            cout << " | Predecessor: ";
            if (ptr->left != nullptr)
                cout << ptr->left->data;
            else
                cout << "NULL";
        }

        if (ptr->rthread)
        {
            cout << " | Successor: ";
            if (ptr->right != nullptr)
                cout << ptr->right->data;
            else
                cout << "NULL";
        }

        cout << endl;
        ptr = successor(ptr);
    }
}

// Reverse inorder traversal using threads
void reverseThreaded(Node* root)
{
    Node* ptr = root;

    if (ptr == nullptr)
        return;

    while (!ptr->rthread)
        ptr = ptr->right;

    cout << "Reverse Inorder Using Threads: ";

    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = predecessor(ptr);
    }

    cout << endl;
}

// Conventional reverse inorder traversal
void reverseConventional(Node* root)
{
    if (root == nullptr)
        return;

    if (!root->rthread)
        reverseConventional(root->right);

    cout << root->data << " ";

    if (!root->lthread)
        reverseConventional(root->left);
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);

    int key;
    cout << "Enter node to find predecessor: ";
    cin >> key;

    Node* ptr = root;

    while (ptr != nullptr)
    {
        if (key == ptr->data)
            break;

        if (key < ptr->data)
        {
            if (ptr->lthread)
                ptr = nullptr;
            else
                ptr = ptr->left;
        }
        else
        {
            if (ptr->rthread)
                ptr = nullptr;
            else
                ptr = ptr->right;
        }
    }

    if (ptr == nullptr)
    {
        cout << "Node not found!\n";
    }
    else
    {
        Node* pred = predecessor(ptr);

        if (pred != nullptr)
            cout << "Inorder Predecessor of "
                 << key << " is " << pred->data << endl;
        else
            cout << "No inorder predecessor exists.\n";
    }

    displayThreads(root);

    reverseThreaded(root);

    cout << "Reverse Inorder Using Conventional BST: ";
    reverseConventional(root);
    cout << endl;

    return 0;
}
