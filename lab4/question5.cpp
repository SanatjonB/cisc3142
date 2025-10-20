#include <iostream>
using namespace std;
int main() {
    int n;
    double e = 2.0; 
    double factorial;
    cout<< "Enter n";
    cin>>n;
    for (int i=2;i<= n; ++i) {
        factorial = 1.0;
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }
        e += 1.0 / factorial;
    }
    cout << "apprx of e for n ="<<n <<" is"<<e<<endl;
    return 0;
}