#include<iostream>

using namespace std;

int partition(int arr[], int start, int end){
  int pivot = arr[end];
  int i = start - 1;

  for (int j = start; j < end; j++){
    if(arr[j]<pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1] , arr[end]);
  
  return i+1;
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