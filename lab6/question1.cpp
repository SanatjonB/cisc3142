#include <iostream>
using namespace std;

int seqSearch(const int list[], int listLength, int searchItem) {
    for (int i = 0; i < listLength; i++) {
        if (list[i] == searchItem)
            return i;  
    }
    return -1;  
}
int main() {
    const int maxSize =5;
    int numbers[maxSize]= {10, 25, 37, 42, 59};
    int target;
    cout <<"Enter the number to search for: ";
    cin >> target;
    int result =seqSearch(numbers, maxSize, target);
    if (result != -1)
        cout<< "Found at index"
     << result << endl;
    else
        cout << "Not found"<< endl;
    return 0;
}
