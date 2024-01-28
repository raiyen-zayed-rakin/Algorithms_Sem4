#include<iostream>
#include<math.h>
using namespace std;

float calculateArea(float L1, float L2, float L3){
  float s = (L1 + L2 + L3)/2;
  float result = sqrt(s*(s-L1)*(s-L2)*(s-L3));
  return result;   
}

int main(){
  float l1, l2, l3;
  cout<<"Enter your 1st side of the traingle : ";
  cin>>l1;

  cout<<"Enter your 2nd side of the traingle : ";
  cin>>l2;

  cout<<"Enter your 3rd side of the traingle : ";
  cin>>l3;
  
  cout<<"Area of the traingle : ";

  cout<<calculateArea(l1, l2 ,l3);
  
  return 0;
}