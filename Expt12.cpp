#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_vector(string title, vector<int> vec) {
    cout << title << ": ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec;
    int choice;
    int element, oldElement, newElement;

    cout << "Enter the number of elements in the vector: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        vec.push_back(element);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Remove an element\n";
        cout << "2. Replace an element\n";
        cout << "3. Display vector\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter element to remove: ";
                cin >> element;
                vector<int> removed_vec;
                remove_copy(vec.begin(), vec.end(), back_inserter(removed_vec), element);
                vec = removed_vec;
                display_vector("Vector after remove_copy", vec);
                break;
            }
            case 2: {
                cout << "Enter element to replace: ";
                cin >> oldElement;
                cout << "Enter new element: ";
                cin >> newElement;
                vector<int> replaced_vec;
                replace_copy(vec.begin(), vec.end(), back_inserter(replaced_vec), oldElement, newElement);
                vec = replaced_vec;
                display_vector("Vector after replace_copy", vec);
                break;
            }
            case 3:
                display_vector("Current vector", vec);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
