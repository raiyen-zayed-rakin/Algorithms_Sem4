#include<iostream>

using namespace std;

long calculateAge(long age){
  int leapYear = age/4;
  double day = (leapYear*366) + (age-leapYear)*365;
  long result = day*86400;
  return result;
}

int main(){
  long age;
  cout<<"Enter your age in years : ";
  cin>>age;

  cout<<"Your age in seconds : ";

  cout<<calculateAge(age);
  
  return 0;
}