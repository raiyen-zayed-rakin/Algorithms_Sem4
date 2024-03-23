#include<iostream>

using namespace std;

void BubbleSort(int arr[], int size){
  int swap;
  int pass = 1;
  while(swap != 0){
    swap = 0;
    cout<<"Pass : "<<pass<<endl;
    for (int k = 0; k < size; k++)
    {
      cout<<arr[k]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < size-1; i++)
    {
      if(arr[i] > arr[i+1]){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        swap++;
      }
    }
    pass++;
  }
}

void printArray(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<" ";
  }
}
int main()
{
  int n;
  cout<<"Enter size : ";
  cin>>n;

  int arr[n];

  cout<<"Enter elements for the array : "<<endl;
  for (int i = 0; i < n; i++)
  {
    cout<<"arr["<<i<<"] : ";
    cin>>arr[i];
    cout<<endl;
  }
  cout<<endl;

  cout<<"Current unsorted array : ";
  printArray(arr, n);

  cout<<endl<<endl;

  //function call
  BubbleSort(arr, n);
  
  cout<<"New sortted array : ";
  printArray(arr, n);
  cout<<endl<<endl;
  return 0;
}
