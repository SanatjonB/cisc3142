// 2)	The cost of renting a room at a hotel is, say $100.00 per night. 

// •	For special occasions, such as a wedding or conference, the hotel offers a special discount as follows: If the number of rooms booked is at least 10, the discount is 10%; at least 20, the discount is 20%; and at least 30, the discount is 30%. Also if rooms are booked for at least three days, then there is an additional 5% discount. 

// Write a program that prompts the user to enter the cost of renting one room, the number of rooms booked, the number of days the rooms are booked, and the sales tax (as a percent). 

// The program outputs the cost of renting one room, the discount on each room as a percent, the number of rooms booked, the number of days the rooms are booked, the total cost of the rooms, the sales tax, and the total billing amount. Your program must use appropriate named constants to store special values such as various discounts.
#include <iostream>
using namespace std;

int main(){
    const double roomCost = 100.00;
    const double discountAtleastTen = .10;
    const double discountAtleastTwenty = .2;
    const double discountAtleastThirty = .3;
    const double discountAtleastThreeDays = .05;
    double salesTax;
    double roomTotalDiscount = 0.0;
    int numberOfDaysBooked;
    int numberOfRoomsBooked;

    cout<<"number of rooms booked, number of days booked, What is sales tax as a percentage so if its 10% enter 10 ";
    cin>>numberOfRoomsBooked>>numberOfDaysBooked>>salesTax;
    salesTax = salesTax/100;

    if (numberOfRoomsBooked >= 30)
        roomTotalDiscount = discountAtleastThirty;
    else if (numberOfRoomsBooked >= 20)
        roomTotalDiscount = discountAtleastTwenty;
    else if (numberOfRoomsBooked >= 10)
        roomTotalDiscount = discountAtleastTen;

    if (numberOfDaysBooked >= 3)
        roomTotalDiscount += discountAtleastThreeDays;

    double discountedRoomCost = roomCost * (1-roomTotalDiscount); 
    double totalCost = discountedRoomCost * numberOfRoomsBooked * numberOfDaysBooked;
    double totalTax = totalCost * salesTax;
    double finalBill = totalTax + totalCost;

    cout << "\n--- Billing Summary ---\n";
    cout << "Cost per room: $" << roomCost << endl;
    cout << "Discount applied: " << roomTotalDiscount * 100 << "%" << endl;
    cout << "Rooms booked: " << numberOfRoomsBooked << endl;
    cout << "Days booked: " << numberOfDaysBooked << endl;
    cout << "Total before tax: $" << totalCost << endl;
    cout << "Sales Tax: $" << totalTax << endl;
    cout << "Final Billing Amount: $" << finalBill << endl;

    return 0;

};