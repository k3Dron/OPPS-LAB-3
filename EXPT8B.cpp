#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class generic_vec {
    vector<T> vec;
public:
    void create(size_t size, T initial_val) {
        vec = vector<T>(size, initial_val);
    }

    void exchange_val(size_t index, T new_val) {
        if (index < vec.size()) {
            vec[index] = new_val;
        } else {
            cout << "Out of bound" << endl;
        }
    }

    void display() {
        for (const auto &vector_el : vec) {
            cout << vector_el << " ";
        }
        cout << endl;
    }
};

int main() {
    generic_vec<int> a;
    a.create(5, 0);
    a.exchange_val(2, 3);
    a.display();

    generic_vec<char> b;
    b.create(3, 'a');
    b.exchange_val(2, 'e');
    b.display();

    return 0;
}
