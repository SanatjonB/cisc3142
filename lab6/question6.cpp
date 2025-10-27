#include <iostream>
using namespace std;

namespace myMath {
    void add(int a[3][3], int b[3][3], int result[3][3]) {
        for (int i = 0; i < 3;i++) {
            for (int j = 0; j< 3;j++) {
                result[i][j] = a[i][j] +b[i][j];
            }
        }
    }
    void subtract(int a[3][3], int b[3][3], int result[3][3]) {
        for (int i = 0;i< 3; i++) {
            for (int j = 0;j < 3; j++) {
                result[i][j] = a[i][j]- b[i][j];
            }
        }
    }
} 

int main() {
    int A[3][3] ={ {1,2, 3},
                    {4, 5,6},
                    {7,8, 9} };

    int B[3][3] = { {9, 8, 7},
                    {6, 5,4},
                    {3,2, 1} };

    int result[3][3];
// add two matrices
    cout << "Matrix Addition------ "<<endl;
    myMath::add(A, B, result);
    for (int i = 0; i< 3;i++) {
        for (int j =0; j < 3; j++) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
// subtract two matrices
    cout << "----Matrix Subtraction:---"<<endl;
    myMath::subtract(A, B, result);
    for (int i =0; i <3; i++) {
        for (int j = 0; j< 3; j++) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}
