#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}

    void* operator new(size_t size) {
        void* p = ::operator new(size);
        return p;
    }

    void operator delete(void* p) {
        ::operator delete(p);
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int val) {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr) {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;
            delete curr;
        }
    }

    LinkedList operator +(int a) {
        this->addNode(a);
        return *this;
    }

    LinkedList operator -(int a) {
        this->deleteNode(a);
        return *this;
    }

    void display() {
        Node* temp = head;
        cout << "(";
        while (temp != nullptr) {
            cout << " " << temp->data << " ";
            temp = temp->next;
        }
        cout << ")\n";
    }
};

int main() {
    LinkedList node;
    node + 2;
    node + 3;
    node + 5;
    node + 8;
    cout << "Initial list: ";
    node.display();
    node - 3;
    cout << "Modified list: ";
    node.display();
    return 0;
}
