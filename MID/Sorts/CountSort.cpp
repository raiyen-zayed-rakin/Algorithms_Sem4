#include<iostream>

using namespace std;

void QuickSort(int arr[], int size){

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
    //result[--ActualCount[arr[i]]] = arr[i];
  }
  
  for (int i = 0; i < size; i++)
  {
    arr[i] = result[i];
  } 
  delete[] ActualCount;
}

int main(){

  int arr[17] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,0};

  QuickSort(arr, 17);

  for (int i = 0; i < 17; i++)
  {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}