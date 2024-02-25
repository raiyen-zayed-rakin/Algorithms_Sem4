#include<iostream>

using namespace std;

class Product{
  public:
  int weight;
  int price;
};

int main(){
  int n;
  cout<<"Enter how many products are there : ";
  cin>>n;

  Product product[n];

  for (int i = 0; i < n; i++)
  {
    cout<<"Enter weight of product No."<<i+1<<" : ";
    cin>>product[i].weight;
    cout<<"Enter price/benefit of product No."<<i+1<<" : ";
    cin>>product[i].price;
  }

  
  




  return 0;
}