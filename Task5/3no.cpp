//Write a program to implement the algorithm of selection sort.
#include<iostream>
using namespace std;
void SelectionSort(int arr[], int n){
  for(int i = 0;i < n-1;i++){
        int k = i;
        for(int j = i+1; j <n;j++){
            if(arr[k] > arr[j])
            k = j;
        }
        if(i != k){
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            cout<<"Step : "<<i<<endl;
            for (int i = 0; i < n; i++)
            {
              cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
  }
  cout<<endl;
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

  cout<<"Current unsortted array : ";
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;

  SelectionSort(arr, n);
  cout<<"New sortted array : ";
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl<<endl;

  return 0;
}
