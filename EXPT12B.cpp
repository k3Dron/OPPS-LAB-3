#include <iostream>
#include <list>

using namespace std;

void displayList(const list<int>& myList) {
    cout << "List elements: ";
    for (list<int>::const_iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void addElements(list<int>& myList) {
    int n, element;
    cout << "Enter the number of elements to add: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        myList.push_back(element);
    }
}

void removeElement(list<int>& myList) {
    int element;
    cout << "Enter element to remove: ";
    cin >> element;
    myList.remove(element);
}

void addElementToFront(list<int>& myList) {
    int element;
    cout << "Enter element to add to front: ";
    cin >> element;
    myList.push_front(element);
}

void sortList(list<int>& myList) {
    myList.sort();
}

int main() {
    list<int> myList;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Elements\n";
        cout << "2. Display List\n";
        cout << "3. Remove Element\n";
        cout << "4. Add Element to Front\n";
        cout << "5. Sort List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addElements(myList);
                break;
            case 2:
                displayList(myList);
                break;
            case 3:
                removeElement(myList);
                break;
            case 4:
                addElementToFront(myList);
                break;
            case 5:
                sortList(myList);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
