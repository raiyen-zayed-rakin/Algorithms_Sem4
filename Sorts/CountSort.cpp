#include<iostream>

using namespace std;

void QuickSort(int arr[], int start, int end){

  int highest = arr[0];

  for (int i = 1; i < end; i++)
  {
    if(arr[i] > highest){
      highest = arr[i];
    }
  }
  
  int ActualCount[highest] = {0};

  for (int i = 0; i < highest; i++)
  {
    if(arr[i] == i){
      ActualCount[i]++;
    }
  }
  for (int i = 1; i < highest; i++)
  {
    ActualCount[i] = ActualCount[i-1] + ActualCount[i];
  }

  int result[end+1];
  int i = end;
  while(highest <= 0){
    if(arr[i] == highest){
      result[i] = arr[i];
      i--;
      ActualCount[highest]--;
    }
  }
  //v aebtagerbg
  

}

int main(){

  int arr[17] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,0};

  QuickSort(arr, 0, 16);

  for (int i = 0; i < 17; i++)
  {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}