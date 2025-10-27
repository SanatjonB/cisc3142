#include <iostream>
#include <string>
using namespace std;

string reverseString(string text);
int main() {
    string word;
    cout<<"Enter a word-";
    cin >> word;
    string result = reverseString(word);
    cout << "Reversed string is  "<< result<< endl;
    return 0;
}
string reverseString(string text) {
    string reversed = "";
    for (int i = text.length() - 1;i >=0; i--) {
        reversed.append(1, text[i]); 
    }
    return reversed;
}