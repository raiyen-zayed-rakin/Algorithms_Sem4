#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;



int main(){
  ll n;
  cin>>n;
  ll arr[n];

  ll sum = 0;
  for (ll i = 0; i < n-1; i++)
  {
    cin>>arr[i];
    sum += arr[i];
  }
  ll check = 0;
  for (ll i = 0; i <= n; i++)
  {
    check += i;
  }

  cout<<check-sum<<endl;
  

  
   
  return 0;
}