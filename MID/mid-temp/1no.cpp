/*
Suppose, You have gone to super shop to buy some groceries and your shopping bag capacity is 10kg. In the Grocery shop, there are products as follows: 3kg rice 470tk, 2kg salt 230tk, 3kg sugar 360tk, 5kg onion 500tk and many more. But You have to buy the expensive products to maximize your profit but not exceeding the limit of bag your capacity. Write a program to print to display the selected items with quantity, price and the total value. 
*/

#include <iostream>
using namespace std;
class Product {
    public:
    string name;
    int weight;
    int price;
    double valuePerUnit;
};

void selectedNotes(int ammount){
  int numOfNotes = 0;
  int Notes[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int selectedNote[10] = {0};
  int temp = ammount;
  while(temp != 0){
    if(temp >= 1000){
      temp -= 1000;
      selectedNote[0]++;
      numOfNotes++;
    }
    else if(temp >= 500){
      temp -= 500;
      selectedNote[1]++;
      numOfNotes++;
    }    
    else if(temp >= 200){
      temp -= 200;
      selectedNote[2]++;
      numOfNotes++;
    }    
    else if(temp >= 100){
      temp -= 100;
      selectedNote[3]++;
      numOfNotes++;
    }    
    else if(temp >= 50){
      temp -= 50;
      selectedNote[4]++;
      numOfNotes++;
    }    
    else if(temp >= 20){
      temp -= 20;
      selectedNote[5]++;
      numOfNotes++;
    }    
    else if(temp >= 10){
      temp -= 10;
      selectedNote[6]++;
      numOfNotes++;
    }    
    else if(temp >= 5){
      temp -= 5;
      selectedNote[7]++;
      numOfNotes++;
    }    
    else if(temp >= 2){
      temp -= 2;
      selectedNote[8]++;
      numOfNotes++;
    }
    else if(temp >= 1){
      temp -= 1;
      selectedNote[9]++;
      numOfNotes++;
    }
  }

  cout<<"Number of notes used : "<<numOfNotes<<endl;
  for (int i = 0; i < 10; i++)
  {
    cout<<"Number of "<<Notes[i]<<" bills used : "<<selectedNote[i]<<endl;
  }
  
}

int main() {
    int bagCapacity = 10;
    int numProducts = 4; 
    Product products[numProducts] = {
        {"rice", 5, 450, 0},
        {"salt", 3, 240, 0},
        {"sugar", 6, 660, 0},
        {"onion", 5, 600, 0}
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
    
    
    selectedNotes(totalPrice);
    return 0;
}
