#include<iostream>

using namespace std;

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = high;

  for (int j = high-1; j >= low; j--){
    if(arr[j]>pivot){
      i--;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i] , arr[high]);
  
  return i;
}

void QuickSort(int arr[], int start, int end){
  if(start >= end){
    return;
  }
  //main method
  int p = partition(arr, start, end);
  //left part
  QuickSort(arr, start, p-1);
  //right part
  QuickSort(arr, p+1, end);
}

int main(){

  int arr[9] = {2,4,1,6,9,9,9,5,6};

  QuickSort(arr, 0, 8);

  for (int i = 0; i < 9; i++)
  {
    cout<<arr[i]<<" ";
  }

 
  return 0;
}