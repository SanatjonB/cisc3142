#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int Num_salesPerson = 6;
const int Num_quarters = 4;

struct salesPersonRec {
    int ID;
    double quarter[Num_quarters];
    double totalSale;
};
void initialize(ifstream& indata, salesPersonRec list[], int listSize);
void getData(ifstream& infile, salesPersonRec list[], int listSize);
void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[]);
void totalSaleByPerson(salesPersonRec list[], int listSize);
void printReport(ofstream& outfile, salesPersonRec list[], int listSize, double saleByQuarter[]);
void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize);
void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]);
int main() {
    ifstream inData;
    ifstream salesData;
    ofstream outData;

    string idFile, salesFile, outFile;

    salesPersonRec salesPersonList[Num_salesPerson];
    double totalSaleByQuarter[Num_quarters];

    cout << "Enter the salesperson ID file name: ";
    cin >> idFile;
    inData.open(idFile);
    if (!inData) {
        cerr << "Error: Cannot open ID file."<<endl;
        return 1;
    }

    initialize(inData, salesPersonList, Num_salesPerson);
    inData.close();

    cout << "Enter the sales data file name: ";
    cin >> salesFile;
    salesData.open(salesFile);
    if (!salesData) {
        cerr << "Error: Cannot open sales data file."<<endl;
        return 1;
    }

    cout << "Enter the output file name: ";
    cin >> outFile;
    outData.open(outFile);
    if (!outData) {
        cerr << "Error: Cannot create output file."<<endl;
        return 1;
    }

    outData << fixed << showpoint << setprecision(2);

    getData(salesData, salesPersonList, Num_salesPerson);
    saleByQuarter(salesPersonList, Num_salesPerson, totalSaleByQuarter);
    totalSaleByPerson(salesPersonList, Num_salesPerson);

    printReport(outData, salesPersonList, Num_salesPerson, totalSaleByQuarter);
    maxSaleByPerson(outData, salesPersonList, Num_salesPerson);
    maxSaleByQuarter(outData, totalSaleByQuarter);

    salesData.close();
    outData.close();

    cout << "Report generated successfully."<<endl;
    return 0;
}
// intinilization part 1 
void initialize(ifstream& indata, salesPersonRec list[], int listSize) {
    for (int i=0; i < listSize;i++) {
        indata>>list[i].ID;
        list[i].totalSale = 0.0;
        for (int j = 0; j <Num_quarters; j++)
            list[i].quarter[j] =0.0;
    }
}

void getData(ifstream& infile, salesPersonRec list[], int listSize) {
    int ID, month;
    double amount;

    while (infile>> ID>> month>>amount) {
        for (int i = 0; i< listSize; i++) {
            if (list[i].ID == ID){
                int quarterIndex=(month - 1) / 3;
                list[i].quarter[quarterIndex]+= amount;
                break;
            }
        }
    }
}

void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[]) {
    for (int q = 0; q < Num_salesPerson; q++){
        totalByQuarter[q] = 0.0;
        for (int i = 0; i < listSize; i++){
            totalByQuarter[q] += list[i].quarter[q];
        }
    }
}

void totalSaleByPerson(salesPersonRec list[], int listSize) {
    for(int i =0; i < listSize;i++){
        list[i].totalSale = 0.0;
        for (int q = 0;q< Num_quarters;q++)
            list[i].totalSale += list[i].quarter[q];
    }
}

void printReport(ofstream& outfile, salesPersonRec list[], int listSize, double saleByQuarter[]) {
    outfile << "              Annual Sales Report                   " <<endl;
    outfile << "_____________________________________________________"<<endl;
    outfile << "ID        QT1        QT2        QT3        QT4      TOTAL"<<endl;
    outfile << "_____________________________________________________"<<endl;

    for (int i = 0; i < listSize; i++) {
        outfile << setw(6) << list[i].ID;
        for (int q = 0; q < Num_quarters; q++)
            outfile << setw(12) << list[i].quarter[q];
        outfile << setw(12) << list[i].totalSale << endl;
    }

    outfile<<"_____________________________________________________"<<endl;
    outfile<< "Total is ";
    for (int q = 0; q < Num_quarters; q++)
        outfile<<setw(12) <<saleByQuarter[q];
    outfile<<endl;
    outfile<< "___________________________________________________________"<<endl;
}
void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize) {
    double maxSale = list[0].totalSale;
    int maxID = list[0].ID;

    for (int i = 1; i < listSize; i++) {
        if (list[i].totalSale>maxSale) {
            maxSale=list[i].totalSale;
            maxID=list[i].ID;
        }
    }
    outData <<"Salesperson with max sales: "<< maxID<<" ($"<< maxSale <<")"<<endl;
}


void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]) {
    int maxQuarter = 0;
    double maxSale = saleByQuarter[0];

    for (int q = 1; q< Num_quarters;q++) {
        if (saleByQuarter[q]> maxSale) {
            maxSale =saleByQuarter[q];
            maxQuarter=q;
        }
    }
    outData<< "Quarter with max sales: QT"<<(maxQuarter + 1)<<" ($"<< maxSale<< ")" <<endl;
}
