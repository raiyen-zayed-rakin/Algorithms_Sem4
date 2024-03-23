#include<iostream>

using namespace std;

float calculateArea(float height, float base){
  float area = 0.5 * height * base;

  return area;
}

int main(){
  float height;
  cout<<"Enter the height of the triangle : ";
  cin>>height;
  float base;
  cout<<"Enter the base of the triangle : ";
  cin>>base;

  cout<<"Area of the traingle : ";

  cout<<calculateArea(height, base);
  
  return 0;
}