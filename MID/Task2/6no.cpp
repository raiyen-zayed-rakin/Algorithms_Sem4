#include<iostream>
using namespace std;

bool checkPrime(int num){
  bool flag = true;
  for (int i = 2; i < num; i++)
  {
    if(num % i == 0){
      flag = false;
    }
  }
  return flag;
}

void sum_ave_ofPrimeNumbers(int range){
  int sum = 0;
  float primeCount = 0;
  for (int i = 2; i <= range; i++)
  {
    if(checkPrime(i)){
      sum += i;
      primeCount++;
    }
  }
  cout<<"Summation of all prime number in the range of "<<range<<" : "<<sum<<endl;
  float ave = sum/primeCount;
  cout<<"Average of all prime number in the range of "<<range<<" : "<<ave<<endl;
  
}

int main()
{ 
  int range = 100;
  sum_ave_ofPrimeNumbers(range);
  return 0;
}
