#include <iostream>
using namespace std;
int main() {
    int num;
    cout  << "Enter an integer between 0 and 35: ";
    cin >>  num;
    if (num <= 9) {
        cout << "Output: " << num << endl;
    } 
    else {
        char result = static_cast<char>('A' + (num - 10));
        cout << result << endl;
    }

    return 0;
}
