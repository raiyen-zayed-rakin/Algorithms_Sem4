/*
Consider the following array: [15, 22,25, 0, -1, -2,-6,-12, 5] now, sort this array using best performing technique and find an element from it using best performing process. 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = high;

  for (int j = high-1; j >= low; j--)
  {
    if(arr[j] > pivot){
      i--;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

void QuickSort(int arr[], int low, int high){
  if(low >= high){
    return;
  }
  int p = partition(arr, low, high);

  QuickSort(arr, low, p-1);
  QuickSort(arr, p+1, high);
}
void BinarySearch(int arr[], int size, int target){
  
  cout<<"Current array : "<<endl;
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
  int first = 0;
  int last = size - 1; 
  int mid = 0;
  while(first <= last){
    mid = (first + last)/2;

    if(arr[mid] == target){
      cout<<"Found at index : "<<mid<<endl;
      return;
    } 
    if(arr[mid] < target){
      first = mid + 1;
    }
    else if(arr[mid] > target){
      last = mid - 1;
    }
  }
  cout<<"Not found."<<endl;
}

void printArr(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<", ";
  }
  cout<<endl;
}

int main(){

  int arr[] = {15,22,25,0,-1,-2,-6,-12,5};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout<<"Best sorting for this array is QuickSort.(By taking last element as the pivot)"<<endl;
  int low = 0;
  int high = size;
  QuickSort(arr, low, high);

  printArr(arr, size);
  cout<<"Best searching for this array is Binary Search.O(long)"<<endl;
  int target; 
  cout<<"Enter your target: ";
  cin>>target;
  BinarySearch(arr, size, target);
  return 0;
}