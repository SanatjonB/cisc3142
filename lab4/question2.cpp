//2)	Write a program that prints first n Fibonacci numbers. ( User enters the value of n)
#include <iostream>
using namespace std;

int main(){
    int numFeb;
    int a = 0;
    int b = 1;
    cout<<"How many fibonacci numbers you want? ";
    cin>>numFeb;

    for(inti = 0; i<numFeb; ++i){
        cout<<a<<" ";
        int nextNum = a+b;
        a=b;
        b=nextNum;
    };

    return 0;
}