#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string name;
    float price;
    Node *left, *right;
};

Node* createNode(int id, string name, float price)
{
    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->price = price;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int id, string name, float price)
{
    if (root == nullptr)
        return createNode(id, name, price);

    if (id < root->id)
        root->left = insert(root->left, id, name, price);
    else if (id > root->id)
        root->right = insert(root->right, id, name, price);
    else
        cout << "Product ID already exists!\n";

    return root;
}

void display(Node* root)
{
    if (root != nullptr)
    {
        display(root->left);
        cout << "ID: " << root->id
             << "  Name: " << root->name
             << "  Price: " << root->price << endl;
        display(root->right);
    }
}

Node* search(Node* root, int id)
{
    if (root == nullptr || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

Node* minimum(Node* root)
{
    while (root != nullptr && root->left != nullptr)
        root = root->left;

    return root;
}

Node* deleteProduct(Node* root, int id)
{
    if (root == nullptr)
        return root;

    if (id < root->id)
        root->left = deleteProduct(root->left, id);
    else if (id > root->id)
        root->right = deleteProduct(root->right, id);
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minimum(root->right);
        root->id = temp->id;
        root->name = temp->name;
        root->price = temp->price;
        root->right = deleteProduct(root->right, temp->id);
    }

    return root;
}

int main()
{
    Node* root = nullptr;
    int choice, id;
    string name;
    float price;

    do
    {
        cout << "\n1. Add Product";
        cout << "\n2. Search Product";
        cout << "\n3. Display Products";
        cout << "\n4. Delete Product";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Product Price: ";
            cin >> price;
            root = insert(root, id, name, price);
            break;

        case 2:
            cout << "Enter Product ID to search: ";
            cin >> id;

            if (search(root, id))
                cout << "Product Found!\n";
            else
                cout << "Product Not Found!\n";
            break;

        case 3:
            cout << "\nProduct List:\n";
            display(root);
            break;

        case 4:
            cout << "Enter Product ID to delete: ";
            cin >> id;

            if (search(root, id))
            {
                root = deleteProduct(root, id);
                cout << "Product Deleted!\n";
            }
            else
                cout << "Product Not Found!\n";
            break;

        case 5:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
