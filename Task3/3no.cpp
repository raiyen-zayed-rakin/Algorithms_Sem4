#include <iostream>
using namespace std;
void LinearSearch(int arr[], int num, int size)
{
  bool check;
  for (int i = 0; i < size; i++)
  {
    check = false;
    if (arr[i] == num)
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

void insertion(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int j = i - 1;
    int temp = arr[i];
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

int partition(int *arr, int first, int last)
{
  int pivot = arr[last];
  int i = first - 1;

  for (int j = first; j < last; j++)
  {
    if (arr[j] <= pivot)
    {
      swap(arr[j], arr[++i]);
    }
  }
  swap(arr[i + 1], arr[last]);
  return i + 1;
}
void QuickSort(int *arr, int first, int last)
{
  if (first < last)
  {
    int index = partition(arr, first, last);
    QuickSort(arr, first, index - 1);
    QuickSort(arr, index + 1, last);
  }
}
void merge(int arr[], int start, int end)
{
  int mid = (end + start) / 2;

  int len1 = mid - start + 1;
  int len2 = end - mid;

  int *first = new int[len1];
  int *second = new int[len2];

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

  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] < second[index2])
    {
      arr[mainArrayIndex] = first[index1];
      mainArrayIndex++;
      index1++;
    }
    else
    {
      arr[mainArrayIndex] = second[index2];
      mainArrayIndex++;
      index2++;
    }
  }

  while (index1 < len1)
  {
    arr[mainArrayIndex] = first[index1];
    mainArrayIndex++;
    index1++;
  }
  while (index2 < len2)
  {
    arr[mainArrayIndex] = second[index2];
    mainArrayIndex++;
    index2++;
  }

  delete[] first;
  delete[] second;
}

void MergeSort(int arr[], int first, int last)
{
  int mid = (first + last) / 2;

  if (first < last)
  {
    MergeSort(arr, first, mid);
    MergeSort(arr, mid + 1, last);
    merge(arr, first, last);
  }
}

void BinarySearch(int arr[], int size)
{
  cout << "Enter which sorting method you want to apply in your array" << endl;
  cout << "1. Quick Sort \n2. Merge Sort \n3. Insertion Sort" << endl;

  int input;

  cout << "Enter your choice -> ";

  cin >> input;

  if (input == 1)
    QuickSort(arr, 0, size - 1);
  else if (input == 2)
    MergeSort(arr, 0, size - 1);
  else if (input == 3)
    insertion(arr, size);
  else
  {
    cout << "Wrong input" << endl;
    return;
  }

  cout << "Sorted array : ";

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n\n";
  int target;
  cout << "\nEnter the target you want to search -> ";
  cin >> target;
  int first = 0;
  int last = size - 1;
  int mid = 0;
  bool check = true;

  while (first <= last)
  {
    int mid = (first + last) / 2;
    if (arr[mid] == target)
    {
      check = false;
      cout << "Found at index No. : " << mid << endl;
      return;
    }
    else if (arr[mid] < target)
    {
      first = mid + 1;
    }
    else if (arr[mid] > target)
    {
      last = mid - 1;
    }
  }
  if (check)
    cout << "Not Found" << endl;
}
int main()
{
  int size;
  cout << "Enter the size of the array : ";

  cin >> size;
  int arr[size];
  cout << endl;

  for (int i = 0; i < size; i++)
  {
    cout << "Enter element " << i + 1 << " : ";
    cin >> arr[i];
  }
  cout << endl;
  cout << "Your array : ";

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n\n";

  cout << "Select your searching method :\n1. linear Search \n2. Binary Search" << endl;
  cout << "\nEnter your choice number : ";
  int num;
  cin >> num;
  if (num == 1)
  {
    cout << "\nEnter the target you want to search : ";
    cin >> num;
    LinearSearch(arr, num, size);
  }
  else if (num == 2)
  {
    BinarySearch(arr, size);
  }
}
