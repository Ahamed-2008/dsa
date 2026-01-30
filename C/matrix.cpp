#include <iostream>
using namespace std;

class Matrix {
private:
    int size;
    int *arr;

public:
    // Constructor with Member Initializer List
    Matrix(int n) : size(n) {
        arr = new int[n * (n + 1) / 2];
    }

    // 1. DESTRUCTOR: Prevents memory leaks
    ~Matrix() {
        delete[] arr;
    }

    // Setter function for specific elements
    void set(int i, int j, int x) {
        if (i >= j) {
            arr[i * (i - 1) / 2 + (j - 1)] = x;
        }
    }

    // Getter function
    int get(int i, int j) {
        if (i >= j) {
            return arr[i * (i - 1) / 2 + (j - 1)];
        }
        return 0; // Elements above the diagonal are 0
    }

    void create() {
        int x;
        cout << "Enter only the lower triangular elements (" << (size * (size + 1) / 2) << " total): " << endl;
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                    cin >> x;
                    set(i, j, x);
                
            }
        }
    }

    void display() {
        cout << "\nThe Matrix is:" << endl;
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mat(4);
    mat.create();
    mat.display();
    return 0;
}