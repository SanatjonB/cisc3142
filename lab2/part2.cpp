//part 1 includes 
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    //part 2 stream stuff
    ifstream inFile; 
    ofstream outFile;
    //part 3 open the files
    inFile.open("inData.txt");
    outFile.open("outData.txt");
    //part 4 read inputs 
    string firstName, lastName, department;
    inFile>> firstName>>lastName>>department;
    double monthlySalary,bonusPercent, taxPercent;
    inFile >> monthlySalary>> bonusPercent>>taxPercent;
    double distanceTraveled,travelTime;
    inFile >>distanceTraveled >> travelTime;
    int cupsSold;
    double costPerCup;

    //part 5 write output to file 
    inFile >> cupsSold >> costPerCup;
    outFile << "Full Name: " << firstName << " " << lastName << endl;
    outFile << "Department:"<< department <<endl;
    outFile << "Monthly Salary: "<< monthlySalary << endl;
    outFile << "Bonus%: " << bonusPercent <<endl;
    outFile << "Taxes%: " << taxPercent << endl;
    outFile << "Distance Traveled:"<< distanceTraveled <<endl;
    outFile << "Traveled Time: " << travelTime << endl;
    outFile << "Cups Sold: "<< cupsSold << endl;
    outFile << "Cost per Cup: "<< costPerCup<< endl;
//part 6 close files
    inFile.close();
    outFile.close();
    return 0;
}
