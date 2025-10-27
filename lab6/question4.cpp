#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string text);
int main() {
    string word;
    cout <<"Enter a word ";
    cin >> word;
    if (isPalindrome(word))
        cout<< word<< " a palindrome" << endl;
    else
        cout <<word << " not a palindrome"<< endl;

    return 0;
}
bool isPalindrome(string text) {
    int left = 0;
    int right = text.length() - 1;
    while (left< right) {
        if (text[left] !=text[right])
            return false; 
         left++;
        right--;
    }
    return true; 
}