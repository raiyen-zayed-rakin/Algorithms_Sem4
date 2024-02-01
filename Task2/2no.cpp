#include<iostream>

using namespace std;

void BinarySearch(int arr[], int size, int target){
  int first = 0;
  int last = size - 1; 
  int mid = 0;
  bool flag = false;
  while(first <= last){
    mid = (first + last)/2;

    if(arr[mid] == target){
      cout<<"Found at index : "<<mid<<endl;
      flag = true;
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

int main(){
  int n;
  cout<<"Enter the size of the array : ";
  cin>>n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout<<"Enter the element No.["<<i+1<<"] : ";
    cin>>arr[i];
  }
  int target;
  cout<<"Enter the target to search : ";
  cin>>target;

  BinarySearch(arr, n, target);
  return 0;
}