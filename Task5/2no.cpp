#include<iostream>
 
using namespace std;
 
struct GroceryItem {

    string name;

    int weight;

    int price;

};
 
int main() {

     int bag_capacity;

    cout<<"ENter size of your bosta ->";

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
 
    cout << "Available items in the grocery shop:\n";

    for (int i = 0; i < num_items; i++) {

        cout << i + 1 << ". " << items[i].name << " - Weight: " << items[i].weight << "kg, Price: " << items[i].price << "tk\n";

    }
 
    cout << "\nSelecting items to maximize profit:\n";

    for (int i = 0; i < num_items; i++) {

        if (current_weight + items[i].weight <= bag_capacity) {

            cout << "Added: " << items[i].name << " - Quantity: " << items[i].weight << "kg, Price: " << items[i].price << "tk\n";

            current_weight += items[i].weight;

            total_value += items[i].price;

        }

    }
 
    cout << "\nTotal value of selected items: " << total_value << "tk\n";
 
    return 0;

}
