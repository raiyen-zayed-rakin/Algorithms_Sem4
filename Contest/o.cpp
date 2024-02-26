#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;



int main(){
  int t;
  cin>>t;

  //for main check
  int noofMatch[10] = {6,2,5,5,4,5,6,3,7,6};
  
  for (int i = 0; i < t; i++)
  {
    ll a, b;
    cin>>a>>b;

    ll total = a + b;
    ll result = 0;
    while (total > 0)
    {
      int temp = total % 10;
      result += noofMatch[temp];
      total = total / 10;
    }
    
    cout<<result<<endl;
    
  }
  
  
  
  
  

  
   
  return 0;
}