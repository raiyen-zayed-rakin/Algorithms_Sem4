#include<iostream>
#include<algorithm>
using namespace std;

class Product{
  public:
  int weight;
  int price;
};

void partialKnapsack(Product product[], int size, int W){
  double perunit[size];
  int x[size]  = {0};
  for (int i = 0; i < size; i++)
  {
    perunit[i] = (double)product[i].price/(double)product[i].weight;
  }
  sort(perunit, perunit+size);
  reverse(perunit, perunit+size);

  Product *temp = new Product[size];
  
  int tempIndex = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      double ratio_i = static_cast<double>(product[i].price) / product[i].weight;
      double ratio_j = static_cast<double>(product[j].price) / product[j].weight;
      if (ratio_i > ratio_j) {
          Product tempProduct = product[i];
          product[i] = product[j];
          product[j] = tempProduct;
      }
    }
  }
  for (int i = 0; i < size; ++i) {
      temp[i] = product[i];
  }
  reverse(temp, temp+size);
  
  
  int w = 0;
  int i = 0;
  int TotalPrice = 0;
  while (w < W)
  {
    if(temp[i].weight > (W-w)){
      w = w + perunit[i] * (W-temp[i].weight);
      TotalPrice += perunit[i] * temp[i].price;
    }
    else{
      w = w + temp[i].weight; //1
      TotalPrice += temp[i].price; //200
    }
    i++;
  }
  cout<<w<<endl;
  cout<<TotalPrice<<endl;
}

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
    cout<<endl;
  }
  int W;
  cout<<"Enter the weight of the knapsack : ";
  cin>>W;

  partialKnapsack(product, n, W);



  return 0;
}