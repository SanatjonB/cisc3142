//1)	Write a loop that takes whole numbers from the user and sums them until user enters an invalid input (input failure). Prompt the sum at the end.

#include <iostream>
using namespace std;
int main(){
    int number;
    int sum = 0;
    cout<<"enter whole numbers";
    while(cin>>number){
        sum+=number;
    }
    cout<<" Sum of all numbers entered is: "<<sum<<endl;
    return 0;
}
