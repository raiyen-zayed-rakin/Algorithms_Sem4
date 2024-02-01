#include<iostream>
using namespace std;

void CelsiusToFahrenheit(float celsius){
  float fahrenheit = ((9.0/5.0) * celsius) +32;
  cout<<"fahrenheit rasult : "<<fahrenheit;
}
void FahrenheitToCelsius(float fahrenheit){
  float celcius = 5.0/9.0 * (fahrenheit-32);
  cout<<"celsius value : "<<celcius;
}
int main()
{ 
  cout<<"Chosse an option to covert : "<<endl;
  cout<<"1. Celsius to Fahrenheit"<<endl;
  cout<<"2. Fahrenheit to Celsius"<<endl;

  int option;
  cout<<"Option : ";
  cin>>option;

  if(option == 1){
    float celsius;
    cout<<"Enter Celsius Value : ";
    cin>>celsius;
    CelsiusToFahrenheit(celsius);
  }
  else if(option == 2){
   float fahrenheit;
   cout<<"Enter fahrenheit Value : ";
   cin>>fahrenheit;
   FahrenheitToCelsius(fahrenheit);
  }
  else{
    cout<<"Invalid input."<<endl;
  }
  return 0;
}
