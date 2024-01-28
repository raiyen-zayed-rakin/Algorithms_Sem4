#include<iostream>

using namespace std;

float calculateFactorial(int number){
  int fact = 1;

  for (int i = 1; i <= number; i++)
  {
    fact = fact * i;
  }
  
  return fact;
}

int main(){
  int number;
  cout<<"Enter your number : ";
  cin>>number;

  cout<<"Factorial of your number : ";

  cout<<calculateFactorial(number);
  
  return 0;
}