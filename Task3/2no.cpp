#include<iostream>

using namespace std;

void merge(int arr[], int start, int end){

  int mid = (end + start)/2;

  int len1 = mid - start + 1;
  int len2 = end - mid;

  int* first = new int[len1];
  int* second = new int[len2];

  int mainArrayIndex = start;
  for (int i = 0; i < len1; i++)
  {
   first[i] = arr[mainArrayIndex];
   mainArrayIndex++;
  }

  mainArrayIndex = mid + 1;
  for (int i = 0; i < len2; i++)
  {
   second[i] = arr[mainArrayIndex];
   mainArrayIndex++;
  }

  int index1 = 0;
  int index2 = 0;

  mainArrayIndex = start;

  while(index1 < len1 && index2 < len2){
    if(first[index1] < second[index2]){
      arr[mainArrayIndex] = first[index1];
      mainArrayIndex++;
      index1++;
    } 
    else{
      arr[mainArrayIndex] = second[index2];
      mainArrayIndex++;
      index2++;
    }
  }
  
  while (index1 < len1){
    arr[mainArrayIndex] = first[index1];
    mainArrayIndex++;
    index1++;
  }
  while (index2 < len2){
    arr[mainArrayIndex] = second[index2];
    mainArrayIndex++;
    index2++;
  }

  delete[] first;
  delete[] second;
}

void mergeSort(int arr[], int start, int end){
  ///base case
  if(start >= end){
    return;
  }
  int mid = start + (end - start)/2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid+1, end);
  //Main merge after getting out of each recursion** 
  merge(arr, start, end);
}

int main(){
  int n;
  cout<<"Enter the size of your array : ";
  cin>>n;

  cout<<endl;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout<<"Enter element No.[ "<<i<<" ] : ";
    cin>>arr[i];
  }

  cout<<endl<<endl;

  cout<<"Before Merge Sorting : ";
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
  //call
  mergeSort(arr, 0, n-1);

  cout<<"After Merge Sorting : ";
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  
  
  
  return 0;
}