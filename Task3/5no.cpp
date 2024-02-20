#include<iostream>
using namespace std;
/*
Write a program that takes the sales unit price and sales quantity of several items(5 items) and calculates the total sales of seven days and the average sales quantity. All input values must be greater than or equal to 0 and less than or equal to 1,000. In addition, the number of pairs of sales unit and sales quantity does not exceed 100.  
*/
const int MAX_ITEMS = 5;
const int MAX_DAYS = 7;
const int MAX_PAIRS = 100;
const double MIN_VALUE = 0.0;
const double MAX_VALUE = 1000.0;

void inputSalesData(double Unit[MAX_ITEMS][MAX_DAYS], int Quantity[MAX_ITEMS][MAX_DAYS]) {
    for (int day = 0; day < MAX_DAYS; ++day) {
        cout << "\nEnter sales data for day " << day + 1 << ":\n";

        for (int item = 0; item < MAX_ITEMS; ++item) {
            cout << "Enter sales unit price for item " << item + 1 << ": ";
            cin >> Unit[item][day];

            while (Unit[item][day] < MIN_VALUE || Unit[item][day] > MAX_VALUE) {
                cout << "Invalid input. Please enter a value between " << MIN_VALUE << " and " << MAX_VALUE << ": ";
                cin >> Unit[item][day];
            }

            cout << "Enter sales quantity for item " << item + 1 << ": ";
            cin >> Quantity[item][day];

            while (Quantity[item][day] < MIN_VALUE || Quantity[item][day] > MAX_VALUE) {
                cout << "Invalid input. Please enter a value between " << MIN_VALUE << " and " << MAX_VALUE << ": ";
                cin >> Quantity[item][day];
            }
        }
    }
}

void calculateSales(double Unit[MAX_ITEMS][MAX_DAYS], int Quantity[MAX_ITEMS][MAX_DAYS], double * totalSales, double* averageQuantity) {
    *totalSales = 0.0;
    int totalQuantity = 0;

    for (int day = 0; day < MAX_DAYS; ++day) {
        for (int item = 0; item < MAX_ITEMS; ++item) {
            *totalSales += Unit[item][day] * Quantity[item][day];
            totalQuantity += Quantity[item][day];
        }
    }

    *averageQuantity = double(totalQuantity) / (double)(MAX_ITEMS * MAX_DAYS);
}

int main() {
    double Unit[MAX_ITEMS][MAX_DAYS];
    int Quantity[MAX_ITEMS][MAX_DAYS];

    inputSalesData(Unit, Quantity);

    double totalSales, averageQuantity;
    calculateSales(Unit, Quantity, &totalSales, &averageQuantity);

    cout << "\nTotal sales for seven days: " << totalSales << " TK" << endl;
    cout << "Average sales quantity: " << averageQuantity << " units" << endl;

    return 0;
}
