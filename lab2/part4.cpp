#include <iostream>
using namespace std;

int main(){
    double yardLength,radius, spacing;
    const double PI = 3.14;
    cout<<"Enter yard Length homei: ";
    cin>>yardLength;
    cout<<"Enter the radius";
    cin>>radius;
    cout<<"Enter the spacing boy";
    cin>>spacing;

    double treeWidth = (2*radius)+spacing;
    int maxTress = (yardLength + spacing)/treeWidth;
    double totalArea = maxTress * PI *radius*radius;

    cout<<"Max # of trees in this block/area "<<maxTress<<endl;
    cout<<"Total area "<<totalArea<<endl;

    return 0;
}