#include <iostream>
using namespace std;

void reverseDigit(int &num){
 int neg = 0;
 if(num < 0){
  neg = 1;
  num =-num;
 }
 int rev = 0;
 while(num>0){
  rev= rev* 10+ num% 10;
  num /= 10;
 }
 if(neg)
  rev = -rev;
 num = rev;
}

int main(){
 int n;
 cout<<"number? ";
 cin>>n;
 reverseDigit(n);
 cout<<"Reversed ->"<<n<<endl;
 return 0;
}