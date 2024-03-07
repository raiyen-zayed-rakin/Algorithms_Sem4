/*
Suppose your friend has started a 1-to-99 shop and he called you to help him. You found products of two packets are already sorted according to their prices and you are asked to sort those products into a shelf according to their prices. Write a program to implement the technique and find the sales and revenue after one week. 
*/


#include<iostream>

using namespace std;

void  ShelfSolve(int packet1[], int n1, int packet2[], int n2){
  int shelfsize = n1 + n2;
  int shelf[shelfsize];

  int i = 0, j = 0, slf = 0;

  while (i < n1 && j < n2)
  {
    if (packet1[i]<packet2[j]){
      shelf[slf++] = packet1[i++];
    }
    else{
      shelf[slf++] = packet2[j++];  
    }
  }

  while (i < n1){
    shelf[slf++] = packet1[i++];
  }
  while (j < n2){
    shelf[slf++] = packet2[j++];
  }
  cout<<endl<<endl;

  cout<<"Prices of the products sorted: ";
  for (int i = 0; i < shelfsize; i++)
  {
    cout<<shelf[i]<<" ";
  }
  cout<<endl<<endl;
  int sales = 0;
  int revenue = 0;

  for (int i = 0; i < shelfsize; i++)
  {
    sales++;
    revenue += shelf[i];
  }
  
  cout<<"Total sales in one week : "<<sales<<endl;
  cout<<"Revenue in one week : "<<revenue<<endl;
  
}

int main(){
  int n1, n2;
  cout<<"Enter the number of products on the 1st packet : ";
  cin>>n1;
  cout<<"Enter the number of products on the 2nd packet : ";
  cin>>n2;
  int packet1[n1];
  int packet2[n2];

  cout<<"Enter the prices of the products (sorted) of the 1st packet : "<<endl;
  for (int i = 0; i < n1; i++)
  {
    cout<<"Sorted price no."<<i+1<<" for packet1 : "<<endl;
    cin>>packet1[i];
  }
  
  cout<<"Enter the prices of the products (sorted) of the 2nd packet : ";
  for (int i = 0; i < n1; i++)
  {
    cout<<"Sorted price no."<<i+1<<" for packet2 : "<<endl;
    cin>>packet2[i];
  }

  ShelfSolve(packet1, n1, packet2, n2);
  

  return 0;
}