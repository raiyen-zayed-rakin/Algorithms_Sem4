#include<iostream>

using namespace std;

bool calculatePrimeNumber(int number){
  bool flag = true;
  for (int i = 2; i < number/2; i++)
  {
    if(number%i == 0){
      flag = false;
    }
  }
  
  return flag;
}

int main(){
  int number;
  cout<<"Enter your number : ";
  cin>>number;

  cout<<"Result if the number is prime or not : ";

  int result = calculatePrimeNumber(number);
  if(result){
    cout<<"Yes.";
  }
  else{
    cout<<"No.";
  }
  return 0;
}