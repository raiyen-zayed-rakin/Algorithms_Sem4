/*
Suppose, your mother is a well-organized lady and keeps everything properly and perfectly. Now, she has asked to bring a tomatoes from Refrigerator. How do you search it. Write a program to implement your technique. 
*/


#include<iostream>

using namespace std;

class Item{
  public:
  int itemLabel;
  string name;
};

int binarySearch(Item items[], int low, int high, int target) {
    while (low <= high) {
        int mid = (high + low) / 2;

        if (items[mid].itemLabel == target) {
            return mid;
        } else if (items[mid].itemLabel < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
int main(){

  Item items[10] = {
    {0, "orange"},
    {1, "apple"},
    {2, "potato"},
    {3, "tomato"},
    {4, "cheese"},
    {5, "water"},
    {6, "banana"},
    {7, "chili"}, 
    {8, "pudding"},
    {9, "eggs"}
  };
  string itemName;
  cout<<"Enter item name : ";
  cin>>itemName;

  int resultLabel; 
  for (int i = 0; i < 10; i++)
  {
    if(itemName == items[i].name){
      resultLabel = items[i].itemLabel;
      break;
    }
  }

  int result = binarySearch(items, 0, 9, resultLabel);
  
  if(result != -1) {
    cout<<itemName<<" found in the refrigerator at position : "<<result + 1<<"."<< endl;
  } 
  else{
    cout<<itemName<<" not found in the refrigerator."<<endl;
  }


  return 0;
}