#include<iostream>

using namespace std;

void CountSort(int arr[], int size){

  int highest = arr[0];

  for (int i = 1; i < size; i++)
  {
    if(arr[i] > highest){
      highest = arr[i];
    }
  }
  
  int *ActualCount = new int[highest+1]();

  for (int i = 0; i < size; i++)
  {
      ActualCount[arr[i]]++;
  }
  
  for (int i = 1; i <= highest; i++)
  {
    ActualCount[i] = ActualCount[i] + ActualCount[i-1];
  }

  int result[size];
  
  for (int i = size-1; i >= 0; i--)
  {
    ActualCount[arr[i]]--;
    int temp = ActualCount[arr[i]];
    result[temp] = arr[i];
  }
  
  for (int i = 0; i < size; i++)
  {
    arr[i] = result[i];
  } 

  delete[] ActualCount;
}

void printArray(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<" ";
  }
}
int main(){
  int n;
  cout<<"Enter the size of the array : ";
  cin>>n;
  int arr[n];

  cout<<"Enter the element of the array : ";

  for (int i = 0; i < n; i++)
  {
    cout<<"arr["<<i<<"] : ";
    cin>>arr[i];
  }
  cout<<"Before Count Sorting : ";
  printArray(arr, n);
  CountSort(arr, n);
  cout<<endl;
  
  cout<<"After Count Sorting : ";
  printArray(arr, n);
  
  return 0;
}