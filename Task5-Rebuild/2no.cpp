/*
Suppose, You have gone to super shop to buy some groceries and your shopping bag capacity is 10kg. In the Grocery shop, there are products as follows: 3kg rice 470tk, 2kg salt 230tk, 3kg sugar 360tk, 5kg onion 500tk and many more. But You have to buy the expensive products to maximize your profit but not exceeding the limit of bag your capacity. Write a program to print to display the selected items with quantity, price and the total value. 
*/

#include <iostream>
using namespace std;

class product{
    public:
    string name;
    int weight;
    int price;
    double perUnitValue;
};

int main() {
    int bag_capacity = 10;
    cout<<"Your knapsack capacity : "<<bag_capacity<<endl<<endl;
    cout<<"Available products : "<<endl<<endl;
    cout<<"1. 3kg Rice - 470tk."<<endl<<endl;
    cout<<"2. 2kg Rice - 230tk."<<endl<<endl;
    cout<<"3. 3kg Rice - 360tk."<<endl<<endl;
    cout<<"4. 5kg Rice - 500tk."<<endl<<endl;

    product products[4] = {
        {"rice", 3, 470, 0},
        {"salt", 2, 230, 0},
        {"sugar", 3, 360, 0},
        {"onion", 5, 500, 0}  
    };

    
    return 0;
}
