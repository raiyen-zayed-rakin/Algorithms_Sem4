#include<iostream>

using namespace std;

float calculateAverage(int arr[], int size){
  int sum = 0;

  for (int i = 0; i < size; i++)
  {
    sum+=arr[i];
  }
  float average = sum/size;

  return average;
}

int main(){
  int arr[5];

  for (int i = 0; i < 5; i++)
  {
    cout<<"Enter Number No."<<i+1<<" : ";
    cin>>arr[i];
  }
  
  cout<<"Average of your 5 numbers : ";

  cout<<calculateAverage(arr,5);
  
  return 0;
}