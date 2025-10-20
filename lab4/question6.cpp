#include <iostream>
#include <string>
using namespace std;
/// yeet 
bool isPalindrome(string str){
 int len = str.length();
 for(int i=0;i<len/2;i++){
   if(str[i]!=str[len-1-i]){
     return false;
   }
 }
 return true;
}

int main(){
 string s;
 cout<<"string? ";
 cin>>s;
 if(isPalindrome(s))
  cout<<"Palindrome"<<endl;
 else
  cout<<"Not palindrome"<<endl;
 return 0;
}
