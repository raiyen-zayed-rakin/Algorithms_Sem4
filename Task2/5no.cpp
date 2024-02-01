#include<iostream>
using namespace std;

void BankBalance(double initial, float interest, int years){
  double annualBalance = initial + (initial * interest); 
  
  cout<<"Initial Balance : "<<initial<<endl;
  cout<<"Interest : "<<interest<<" (6.5%)"<<endl;
  cout<<"Annual Balance : "<<annualBalance<<endl;
  cout<<"Annual Balance after 6 years : "<<annualBalance*6<<endl;
}

int main()
{
  double intialBalance = 100000.00;
  float interest = 0.065;
  int year = 6;
  BankBalance(intialBalance, interest, 6);

  return 0;
}
