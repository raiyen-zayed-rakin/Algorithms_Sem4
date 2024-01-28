#include<iostream>

using namespace std;

bool calculatePalindromeNumber(int number){
  bool flag = false;
  int result = 0;
  int i = 0;
  while(number != 0)
  {
    int temp = number%10;
    result = result + (temp + (10*i));
    number = number/10;
    i++; 
  }

  if(number == result){
    flag = true;
    return flag;
  }
  else{
    return flag;
  }
}


bool calculatePalindromeNumber2(int number){
  string text = to_string(number);
  bool flag = true;
  for (int i = 0, j = text.length()-1; i < text.length(), j>=0; i++, j--)
  {
    if(text[i] != text[j]){
      flag = false;
    }
    return flag;
  }
  
  
}
int main(){
  int number;
  cout<<"Enter your number : ";
  cin>>number;

  cout<<"Result if the number is palindrome or not : ";

  int result = calculatePalindromeNumber2(number);
  if(result){
    cout<<"Yes.";
  }
  else{
    cout<<"No.";
  }
  return 0;
}