#include<iostream>
using namespace std;

void Square(){
  float side = 0.0;
  cout<<"Enter length of one side of the square : ";
  cin>>side;

  cout<<"Area of the square : "<<side*side<<endl;
}

void Trapezium(){
  float side1, side2, height;
  cout<<"Enter length of the 1st side of the trapezium : ";
  cin>>side1;
  cout<<"Enter length of the 2nd side of the trapezium : ";
  cin>>side2;
  cout<<"Enter length of height of the trapezium : ";
  cin>>height;

  cout<<"Area of the trapezium : "<<0.5 * (side1 + side2) *height<<endl;
}

void Parallelogram(){
  float base, height;
  cout<<"Enter length of the 1st side of the parallelogram : ";
  cin>>base;
  cout<<"Enter length of height of the parallelogram : ";
  cin>>height;

  cout<<"Area of the parallelogram : "<<base*height<<endl;
}
void Rhombus(){
  float diagonal1, diagonal2;
  cout<<"Enter length of the 1st diagonal of the rhombus : ";
  cin>>diagonal1;
  cout<<"Enter length of 2nd diagonal of the rhombus : ";
  cin>>diagonal2;

  cout<<"Area of the parallelogram : "<<0.5 * diagonal1 * diagonal2<<endl;
}


int main()
{ 
  cout<<"Enter an option to calculate the area of that shape : "<<endl;
  cout<<"1. Square"<<endl;
  cout<<"2. Trapezium"<<endl;
  cout<<"3. Paralelogram"<<endl;
  cout<<"4. Rhombus"<<endl;
  int option;

  cout<<"Option : ";
  cin>>option;
  cout<<endl<<endl;
  
  switch (option)
  {
  case 1:
    Square();
    break;
  
  case 2:
    Trapezium();
    break;
  
  case 3:
    Parallelogram();
    break;
  
  case 4:
    Rhombus();
    break;
  
  default:
    break;
  }
  return 0;
}
