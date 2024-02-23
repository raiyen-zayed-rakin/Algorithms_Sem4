// Write a program to to access and calculate the summation of all the elements of any diagonal for a 2d array. 
#include <iostream>
using namespace  std;

const int MAX_SIZE = 100;

int diaSum(int arr[][MAX_SIZE], int size, bool isMainDiagonal) {
    int sum = 0;
    if (isMainDiagonal) {
        for (int i = 0; i < size; ++i) {
            sum += arr[i][i];
        }
    } else {
        for (int i = 0; i < size; ++i) {
            sum += arr[i][size - 1 - i];
        }
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    int arr[MAX_SIZE][MAX_SIZE];

    cout << "Enter elements of the square matrix:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
          cout<<"arr["<<i<<"]["<<j<<"] : ";
          cin>>arr[i][j];
        }
    }

    bool isMainDiagonal;
    cout << "Enter a option : "<<endl;
    cout<<"1. for main/left diagonal."<<endl;
    cout<<"0. for anti/right diagonal: ";
    cin >> isMainDiagonal;

    int sum = diaSum(arr, size, isMainDiagonal);
    if (isMainDiagonal){
        cout << "Sum of elements along the main/left diagonal: " << sum << endl;
    }
    else{
        cout << "Sum of elements along the anti/right diagonal: " << sum << endl;
    }

    return 0;
}
