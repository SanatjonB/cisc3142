#include <iostream>
#include <iomanip> // found on google for percision 
using namespace std;

int main(){
    double kilograms,pounds;

    cout<<"Enter your weight in kilograms: ";
    cin>>kilograms;

    pounds= kilograms*2.2;
    //first attempt
    // double kilogramsRounded = (int)(kilograms*100+0.5)/100.0;
    // double poundsRounded = (int)(pounds*100+.5)/100.0;
    cout<<fixed<<setprecision(2); 
    cout<<"Weight in KiloGrams is "<<kilograms<<endl;
    cout<<"Weight in Pounds is "<<pounds<<endl;
}