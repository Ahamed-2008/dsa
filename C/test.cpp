#include<iostream>
using namespace std;

class Matrix{
    private:
    int *A;
    int n;
    
    public:
    Matrix(int n){
        A = new int[5];
        this -> n = n;
    }
    void set(int i, int j, int x){
        if (i==j) A[i-1] = x;
    }
    
    int get(int i, int j){
        if (i==j) return A[i-1];
        return 0;
    }
    
    void Display(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
    ~Matrix(){
        delete []A;
    }
        
};

int main(){
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    Matrix m(n);
    m.set(1, 1, 1); 
    m.set(2, 2, 2); 
    m.set(3, 3, 3); 
    m.set(4, 4, 4); 
    m.set(5, 5, 5); 
    m.set(6, 6, 6);
    m.Display();
    return 0;
}