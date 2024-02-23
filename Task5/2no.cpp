/*
Suppose, You have gone to super shop to buy some groceries and your shopping bag capacity is 10kg. In the Grocery shop, there are products as follows: 3kg rice 470tk, 2kg salt 230tk, 3kg sugar 360tk, 5kg onion 500tk and many more. But You have to buy the expensive products to maximize your profit but not exceeding the limit of bag your capacity. Write a program to print to display the selected items with quantity, price and the total value. 
*/
#include<iostream>
 
using namespace std;
 
class GroceryItem {
    public:
    string name;
    int weight;
    int price;
};
 
int main() {
    int bag_capacity;
    cout<<"Enter size of your Knapsack : ";
    cin>>bag_capacity;
 
    int num_items =4;
    GroceryItem items[num_items] = {
        {"Rice", 3, 470},
        {"Salt", 2, 230},
        {"Sugar", 3, 360},
        {"Onion", 5, 500}
    };

    int current_weight = 0;
    int total_value = 0;
 
    cout << "Available items in the grocery shop: "<<endl;

    for (int i = 0; i < num_items; i++) {

        cout << i + 1 << ". " << items[i].name << " - Weight: " << items[i].weight << "kg, Price: " << items[i].price << "tk\n";

    }
    cout<<endl;
    cout<<"Selecting items to maximize profit: "<<endl;

    for (int i = 0; i < num_items; i++) {
        if (current_weight + items[i].weight <= bag_capacity) {
            cout << "Added: " << items[i].name << " - Quantity: " << items[i].weight << "kg, Price: " << items[i].price << "tk\n";
            current_weight += items[i].weight;
            total_value += items[i].price;
        }
    }
    cout<<"\nTotal value of selected items: "<<total_value<<"tk"<<endl;
    return 0;

}
