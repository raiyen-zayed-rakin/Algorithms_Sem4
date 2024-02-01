#include<iostream>
#include<algorithm>
using namespace std;

void insertionSort(int arr[], int size){
  int v;
  for(int i=1;i<size;i++){
      v = arr[i];
      int j = i-1;
      while(j>=0 && arr[j] > v){
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = v;
    }
}

void LinearSearch(int arr[], int size, int target){
  bool flag = false;
  int temp = 0;
  for (int i = 0; i < size; i++)
  {
    if(arr[i] == target){
      flag = true;
      temp = i;
    }
  }
  if(flag == true){
      cout<<"Found at index No. : "<<temp<<endl;
  }
  else{
    cout<<"Not found."<<endl;
  }
}
void BinarySearch(int arr[], int size, int target){
  insertionSort(arr, size);
  cout<<"New sortted array : "<<endl;
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

  int choice;
  cout<<"Please, Choose in which method you want to sort this array : "<<endl<<"1. Linear Search"<<endl<<"2. Binary Search"<<endl;
  cout<<"Option : ";
  cin>>choice;
  if(choice == 1){
    LinearSearch(arr, n, target);
  }
  else if(choice == 2){
    BinarySearch(arr, n, target);
  }
  return 0;
}