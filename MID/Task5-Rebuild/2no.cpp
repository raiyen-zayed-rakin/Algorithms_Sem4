/*
Suppose, You have gone to super shop to buy some groceries and your shopping bag capacity is 10kg. In the Grocery shop, there are products as follows: 3kg rice 470tk, 2kg salt 230tk, 3kg sugar 360tk, 5kg onion 500tk and many more. But You have to buy the expensive products to maximize your profit but not exceeding the limit of bag your capacity. Write a program to print to display the selected items with quantity, price and the total value. 
*/


// C++ program to solve fractional Knapsack Problem
 
#include<iostream>
#include<algorithm>
using namespace std;
 
// Structure for an item which stores weight and
// corresponding value of Item
class Item {
    public:
    int profit, weight;
 
    // Constructor
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};
 
// Comparison function to sort Item 
// according to profit/weight ratio
static bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
 
// Main greedy function to solve problem
double fractionalKnapsack(int W, Item arr[], int N)
{
    // Sorting Item on basis of ratio
    sort(arr, arr + N, cmp);
 
    double finalvalue = 0.0;
 
    // Looping through all items
    for (int i = 0; i < N; i++) {
         
        // If adding Item won't overflow, 
        // add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
 
        // If we can't add current Item, 
        // add fractional part of it
        else {
            finalvalue
                += arr[i].profit
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }
 
    // Returning final value
    return finalvalue;
}
 
// Driver code
int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}
