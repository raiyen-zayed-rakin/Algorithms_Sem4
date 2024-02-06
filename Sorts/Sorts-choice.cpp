#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr[], int start, int end){
  int mid = (start + end)/2;

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

  while (index1 < len1 && index2 < len2){
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
  while(index1 < len1){
    arr[mainArrayIndex] = first[index1];
    mainArrayIndex++;
    index1++;
  }
  while(index2 < len2){
    arr[mainArrayIndex] = second[index2];
    mainArrayIndex++;
    index2++;
  }

  delete[] first;
  delete[] second;
}

void mergeSort(int arr[], int start, int end){
  if(start >= end){
    return;
  }
  int mid = (start + end)/2;

  mergeSort(arr, start, mid);
  mergeSort(arr, mid+1, end);

  merge(arr, start,end);
}

int partition(int arr[], int start, int end){
  int pivot = arr[end];

  int count = 0;
  for (int i = start; i < end; i++){
    if(pivot >= arr[i]){
      count++;
    }
  }
  int pivotIndex = start + count;

  swap(arr[pivotIndex], arr[end]);

  int i = start;
  int j = end;
  
  while (i<pivotIndex && j>pivotIndex){
    while(arr[i]<=pivot){
      i++;  
    }
    while (arr[j]>pivot){
      j--;
    }
    if(i<pivotIndex && j>pivotIndex){
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  return pivotIndex;
}

void quickSort(int arr[], int start, int end){
  if(start >= end){
    return;
  }

  int p = partition(arr, start, end); //1

  quickSort(arr, start, p-1);  //0,0
  quickSort(arr, p+1, end);    //2,3
  
}


int main(){

  int arr[9] = {2,4,1,6,9,9,9,5,6};
  int n = 9;
  cout<<"Enter an option to chosse a sort method : "<<endl;
  cout<<"1. Merge Sort"<<endl;
  cout<<"2. Quick Sort"<<endl;
  cout<<"3. Count Sort"<<endl;

  int option;

  cout<<"Option : ";
  cin>>option;

  if(option == 1){    
    mergeSort(arr, 0, n-1);
  }
  else if(option == 2){
    quickSort(arr, 0, n-1);
  }
  else if(option == 3){
    //countSort(arr, 0, n-1);
  }

  for (int i = 0; i < 9; i++)
  {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}