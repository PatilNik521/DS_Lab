#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- BST Menu ---" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Pre-order Traversal" << endl;
        cout << "3. In-order Traversal" << endl;
        cout << "4. Post-order Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
