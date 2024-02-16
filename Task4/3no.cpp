#include <iostream>
using namespace std;
//Linear
void LinearSearch(int arr[], int size, int target)
{
  bool check;
  for (int i = 0; i < size; i++)
  {
    check = false;
    if (arr[i] == target)
    {
      cout << "\nFound at index -> " << i << endl;
      break;
    }
    else
      check = true;
  }
  if (check)
    cout << "\nNot found" << endl;
}
//Binary
void BinarySearch(int arr[], int size, int target){
  int first = 0;
  int last = size - 1; 
  int mid = 0;
  bool flag = false;
  while(first <= last){
    mid = (first + last)/2;

    if(arr[mid] == target){
      cout<<"Found at index : "<<mid<<endl;
      flag = true;
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
//bubble
void BubbleSort(int arr[], int size){
  int swap;
  while(swap != 0){
    swap = 0;
    for (int i = 0; i < size-1; i++)
    {
      if(arr[i] > arr[i+1]){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        swap++;
      }
    }
  }
}
//count
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


int main()
{
  int n;
  cout << "Enter the size of the array : ";

  cin >> n;
  int arr[n];
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    cout << "arr["<<i<<"] : ";
    cin >> arr[i];
  }
  cout << endl;
  cout << "Current array : ";
  printArray(arr, n);
  cout<<endl<<endl;

  int choice;

  cout<<"Select your action : "<<endl;
  cout<<"1. Search"<<endl;
  cout<<"2. Sort"<<endl;

  cin>>choice;
  int option;
  if(choice == 1){
    int target;
    cout<<"Enter target : ";
    cin>>target;
    cout<<"Select your seaching method : "<<endl;
    cout<<"1. Linear Search"<<endl;
    cout<<"2. Binary Search"<<endl;
    
    cin>>option;
    if(option == 1){
      LinearSearch(arr, n, target);
    }
    else if(option == 2){
      BubbleSort(arr, n);
      BinarySearch(arr, n, target);
    }
    else{
      cout<<"Invalid Input.";
    }
  }
  else if(choice == 2){
    cout<<"Select your sorting method : "<<endl;
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Count Sort"<<endl;

    cin>>option;
    if(option == 1){
      BubbleSort(arr, n);
      printArray(arr, n);
    }
    else if(option == 2){
      CountSort(arr, n);
      printArray(arr, n);
    }
    else{
      cout<<"Invalid Input.";
    }
  }
  else{
    cout<<"Invalid Input.";
  }
 



  return 0;
}
