#include <iostream>
using namespace std;

template <typename T>
class BST {
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, T value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void inOrder(Node* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    Node* search(Node* node, T value) const {
        if (node == nullptr || node->data == value) {
            return node;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(T value) {
        insert(root, value);
    }

    void inOrder() const {
        inOrder(root);
        cout << endl;
    }

    Node* search(T value) const {
        return search(root, value);
    }
};

int main() {
    BST<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(7.0);
    bst.insert(20);
    bst.insert(40);
    bst.insert(4.60);
    bst.insert(80);

    cout << "In-order traversal: ";
    bst.inOrder();

    int value = 40;
    if (bst.search(value)) {
        cout << "Value " << value << " found in the BST." << endl;
    } else {
        cout << "Value " << value << " not found in the BST." << endl;
    }

    return 0;
}
