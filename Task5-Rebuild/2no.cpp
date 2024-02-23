#include <iostream>
using namespace std;
struct Product {
    char name[20];
    int weight;
    int price;
    double valuePerUnit;
};

bool compare(Product p1, Product p2) {
    return p1.valuePerUnit > p2.valuePerUnit;
}

int main() {
    const int bagCapacity = 10;
    const int numProducts = 4; 
    Product products[numProducts] = {
        {"rice", 3, 470, 0},
        {"salt", 2, 230, 0},
        {"sugar", 3, 360, 0},
        {"onion", 5, 500, 0}
    };

    for (int i = 0; i < numProducts; i++) {
        products[i].valuePerUnit =(products[i].price) / products[i].weight;
    }
    for (int i = 0; i < numProducts - 1; i++) {
        for (int j = i + 1; j < numProducts; j++) {
            if (products[i].valuePerUnit < products[j].valuePerUnit) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    double totalWeight = 0;
    double totalPrice = 0;

    cout << "Selected items:" << endl;

    for (int i = 0; i < numProducts; i++) {
        if (totalWeight + products[i].weight <= bagCapacity) {
            cout << products[i].name << " - " << products[i].weight << "kg - " << products[i].price << "tk" << endl;
            totalWeight += products[i].weight;
            totalPrice += products[i].price;
        } else {
            double remainingCapacity = bagCapacity - totalWeight;
            double fraction = remainingCapacity / products[i].weight;
            cout << products[i].name << " - " << remainingCapacity << " (fractional) kg - " << fraction * products[i].price << "(fractional) tk" << endl;
            totalWeight += remainingCapacity;
            totalPrice += fraction * products[i].price;
            break;
        }
    }

    cout << "Total value: " << totalPrice << "tk" << endl;
    cout<< "Total weight: " << totalWeight << "kg" << endl;

    return 0;
}
