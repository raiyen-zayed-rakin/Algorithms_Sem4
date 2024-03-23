/*
Write a program to find the common characters between the words Convention and Competitive. 
*/

#include<iostream>

using namespace std;

void common(string s1, string s2){
  string result;
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                result += s1[i];
                break; 
            }
        }
    }
    cout << "Common result: " << result << endl;
}

int main(){

  string s1, s2;
  cout<<"Enter your 2 string to check common characters : "<<endl;
  cout<<"String 1 : ";
  cin>>s1;
  
  cout<<"String 2 : ";
  cin>>s2;

  common(s1, s2);
  
  return 0;
}