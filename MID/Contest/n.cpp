#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;



int main(){
  int t;
  cin>>t;
  int n;
  for (int i = 0; i < t; i++)
  {
    cin>>n;
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
      fact *= i;
    }

    cout<<fact<<endl;
  }
  
  
  

  
   
  return 0;
}