#include <iostream>
using namespace std;
int main(){
    int number;
    int sum = 0;
    cout<<"enter whole numbers";
    while(cin>>number){
        if(number<0){
            continue;
        }
        sum+=number;
    }
    cout<<" Sum of all numbers entered is: "<<sum<<endl;
    return 0;
}
