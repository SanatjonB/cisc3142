#include <iostream>
using namespace std;
int main() {
    double populationA, populationB;
    double rateA, rateB;
    int years = 0;
    cout<< "population of town A? ";
    cin>> populationA;
    cout <<"growth rate of town A? ";
    cin >>rateA;
    cout<<"population of town B: ";
    cin >>populationB;
    cout<<"growth rate of town B: ";
    cin >>rateB;
    rateA/=100;
    rateB/= 100;
    while(populationA <populationB){
        populationA+= populationA *rateA;
        populationB +=populationB*rateB;
        years++;
    }
    cout <<"after" << years <<"years,population of Town A will be greater than or equal to Town B";
    cout <<"Popultion of Town A "<<populationA<<endl;
    cout <<"Population of Town B "<< populationB<<endl;
    return 0;

}
