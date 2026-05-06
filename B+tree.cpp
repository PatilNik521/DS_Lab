#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    bool isLeaf;
    vector<int> keys;
    vector<Node*> ptr;

    Node(bool leaf) {
        isLeaf = leaf;
    }
};

class BPlusTree {
    Node* root;
    int maxKeys;

public:
    BPlusTree(int size) {
        root = NULL;
        maxKeys = size;
    }

    void insert(int val) {
        if (root == NULL) {
            root = new Node(true);
            root->keys.push_back(val);
            return;
        }

        root->keys.push_back(val);

        for (int i = 0; i < root->keys.size(); i++) {
            for (int j = i + 1; j < root->keys.size(); j++) {
                if (root->keys[i] > root->keys[j]) {
                    swap(root->keys[i], root->keys[j]);
                }
            }
        }
    }

    void display() {
        if (root == NULL) {
            cout << "Tree Empty";
            return;
        }

        for (int x : root->keys)
            cout << x << " ";

        cout << endl;
    }
};

int main() {
    int size, choice, val;

    cout << "Enter maximum keys: ";
    cin >> size;

    BPlusTree tree(size);

    do {
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                tree.insert(val);
                break;

            case 2:
                tree.display();
                break;

            case 3:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 3);

    return 0;
}
