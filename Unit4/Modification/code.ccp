#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool rightThread;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        rightThread = true;
    }
};

Node* insert(Node* root, int value)
{
    Node* ptr = root;
    Node* parent = NULL;

    while (ptr != NULL)
    {
        if (value == ptr->data)
        {
            cout << "Duplicate value not allowed.\n";
            return root;
        }

        parent = ptr;

        if (value < ptr->data)
        {
            if (ptr->left == NULL)
                break;
            ptr = ptr->left;
        }
        else
        {
            if (!ptr->rightThread)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* temp = new Node(value);

    if (parent == NULL)
    {
        root = temp;
    }
    else if (value < parent->data)
    {
        temp->right = parent;
        parent->left = temp;
    }
    else
    {
        temp->right = parent->right;
        parent->right = temp;
        parent->rightThread = false;
    }

    return root;
}

Node* search(Node* root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;

        if (key < root->data)
            root = root->left;
        else if (!root->rightThread)
            root = root->right;
        else
            return NULL;
    }

    return NULL;
}

void findPredecessor(Node* root, int key)
{
    Node* current = search(root, key);

    if (current == NULL)
    {
        cout << key << " not found in the tree.\n";
        return;
    }

    if (current->left != NULL)
    {
        Node* pred = current->left;

        while (!pred->rightThread)
            pred = pred->right;

        cout << "Node: " << key
             << ", Predecessor: " << pred->data
             << " (Found through left subtree)\n";
    }
    else
    {
        Node* pred = NULL;
        Node* ptr = root;

        while (ptr != NULL && ptr != current)
        {
            if (key < ptr->data)
                ptr = ptr->left;
            else
            {
                pred = ptr;

                if (!ptr->rightThread)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        if (pred == NULL)
            cout << "Node: " << key
                 << " has no inorder predecessor.\n";
        else
            cout << "Node: " << key
                 << ", Predecessor: " << pred->data
                 << " (Found through thread)\n";
    }
}

int main()
{
    Node* root = NULL;
    int n, value, key, count;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "How many nodes to check? ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter node to find predecessor: ";
        cin >> key;

        findPredecessor(root, key);
    }

    return 0;
}
