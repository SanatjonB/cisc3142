#include <iostream>
using namespace std;
void generateTable(int table[][10], int rows, int columns) {
    for (int i= 0; i < rows;i++){
        for (int j =0; j < columns; j++) {
            table[i][j] =(i + 1) *(j + 1); 
        }
    }
}
int main() {
    const int rows = 10;
    const int columns = 10;
    int table[rows][columns];
    generateTable(table, rows, columns);
    cout << "Multiplication Table (1 to 10):"<<endl;
    for (int i = 0; i< rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout <<table[i][j] << "    ";
        }
        cout << endl;
    }

    return 0;
}
