#include<iostream>

using namespace std;

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

  LinearSearch(arr, n, target);
  return 0;
}