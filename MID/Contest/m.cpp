#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;



int main(){
  ll t;
  cin>>t;
  ll n;
  for (ll i = 0; i < t; i++)
  {
    cin>>n;
    ll count = 0;
    while (n > 0)
    {
      int temp = n % 10;
      if(temp == 4){
        count++;
      }
      n = n / 10;
    }
    cout<<count<<endl;
  }
  
  
  

  
   
  return 0;
}