#include <iostream>
using namespace std;
void selectionSort(int list[], int listLength) {
    for (int i= 0;i < listLength-1;i++) {
        int minIndex = i; 

        for (int j = i + 1; j< listLength;j++) {
            if (list[j]< list[minIndex]){
                minIndex = j;
            }
        }
        int temp = list[i];
        list[i] = list[minIndex];
        list[minIndex] = temp;
    }
}
int main() {
    const int maxSize = 6;
    int numbers[maxSize] = {45, 12, 8, 33, 27, 5};
    cout <<"Original array___";
    for (int i = 0; i< maxSize; i++)
        cout << numbers[i] << " ";
    cout << endl;
    selectionSort(numbers, maxSize);
    cout << "After sort the array___ ";
    for (int i = 0; i < maxSize; i++)
        cout << numbers[i] << " ";
    cout << endl;
    return 0;
}
