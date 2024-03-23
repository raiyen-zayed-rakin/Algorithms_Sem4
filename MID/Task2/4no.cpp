#include<iostream>
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

int main()
{
  int n;
  cout<<"Enter the size of the array : ";
  cin>>n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout<<"Enter the element No.["<<i+1<<"] : ";
    cin>>arr[i];
  }
  cout<<endl<<endl;
  cout<<"Current unsortted array : ";
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;

  insertionSort(arr, n);
  
  cout<<"New sortted array : ";
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;

  return 0;
}
