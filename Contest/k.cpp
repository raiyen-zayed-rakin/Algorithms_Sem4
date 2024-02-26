#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;



int main(){
  ll t;
  cin>>t;

  for (ll i = 0; i < t; i++)
  {
    ll n, k;
    cin>>n>>k;

    ll arr[n];
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
      cin>>arr[i];
      if(arr[i] > k){
        count++;
      }
    }
    cout<<count<<endl;
  }
  
  
  
  
  

  
   
  return 0;
}