#include <iostream>
#include <string>
using namespace std;

class productType
{
public:

    productType()
    {
        productName = "";            
        productID = "";              
        manufacturerName = "";        
        quantityInStock = 0;         
        price = 0.0;                  
        discount = 0.0;              
    }

    productType(int quantity, double itemPrice, double itemDiscount)
    {
        productName = "";
        productID = "";
        manufacturerName = "";

        // making sure no negative values 
        if (quantity>= 0)
            quantityInStock = quantity;
        else
            quantityInStock= 0;

        if (itemPrice >= 0)
            price =itemPrice;
        else
            price =0.0;

        if (itemDiscount >= 0)
            discount= itemDiscount;
        else
            discount = 0.0;
    }

    productType(string idValue, int quantity, double itemPrice, double itemDiscount)
    {
        productName = "";
        manufacturerName = "";
        productID = idValue;

        if (quantity >= 0)
            quantityInStock = quantity;
        else
            quantityInStock = 0;

        if (itemPrice >= 0)
            price = itemPrice;
        else
            price = 0.0;

        if (itemDiscount >= 0)
            discount = itemDiscount;
        else
            discount = 0.0;
    }

    productType(string name, string idValue, string maker, int quantity, double itemPrice, double itemDiscount)
    {
        productName = name;
        productID = idValue;
        manufacturerName = maker;

        if (quantity >= 0)
            quantityInStock = quantity;
        else
            quantityInStock = 0;

        if (itemPrice >= 0)
            price = itemPrice;
        else
            price = 0.0;

        if (itemDiscount >= 0)
            discount = itemDiscount;
        else
            discount = 0.0;
    }

    void set(string name, string idValue, string maker, int quantity, double itemPrice, double itemDiscount)
    {
        productName = name;
        productID = idValue;
        manufacturerName = maker;

        if (quantity >= 0)
            quantityInStock = quantity;
        else
            quantityInStock = 0;

        if (itemPrice >= 0)
            price = itemPrice;
        else
            price = 0.0;

        if (itemDiscount >= 0)
            discount =itemDiscount;
        else
            discount = 0.0;
    }

    void print() const
    {
        cout << "Product Name-" << productName << endl;
        cout << "Product ID-"<< productID<< endl;
        cout << "Manufacturer-" << manufacturerName<< endl;
        cout << "Quantity in Stock-"<< quantityInStock <<endl;
        cout << "Price-" << price <<endl;
        cout << "Discount-" << discount << endl;
    }
    void setQuantityInStock(int quantity)
    {
        quantityInStock = quantity;    // setting stock 
    }
    void updateQuantityInStock(int addedAmount)
    {
        quantityInStock = quantityInStock + addedAmount;   // adding stock
    }
    int getQuantityInStock() const
    {
        return quantityInStock;       
    }
    void setPrice(double newPrice)
    {
        price = newPrice;             // updating 
    }
    double getPrice() const
    {
        return price;                 
    }
    void setDiscount(double newDiscount)
    {
        discount = newDiscount;       // updating 
    }

    double getDiscount() const
    {
        return discount;              
    }

private:
    string productName;
    string productID;
    string manufacturerName;
    int quantityInStock;
    double price;
    double discount;
};

int main()
{
    productType prod1; 
    productType prod2("Apple", "123", "Family Farm", 100, 5.99, 12);

    prod1.set("Pear", "124", "Big Farm", 120, 3.99, 0);

    cout << "Printing prod1----" << endl;
    prod1.print();

    prod1.updateQuantityInStock(10);

    cout << "Updated Quantity of prod1: "
         << prod1.getQuantityInStock() << endl;

    prod1.setPrice(15.5);

    cout << "New Price of prod1: "
         << prod1.getPrice() << endl;

    cout << "All parameters of prod1----" << endl;
    prod1.print();

    return 0;
}
