#include<iostream>
#include<algorithm>
#include<sstream>

#define ll long long

using namespace std;



int main(){
  int n;
  cin>>n;
  ll L,R;
  for (int i = 0; i < n; i++)
  {
    cin>>L>>R;
    ll count = 0;
    for (ll i = L; i <= R; i++)
    {
      
      if((i % 10 == 2) || (i % 10 == 3) || (i % 10 == 9)){
        count++;
      }
    }
    cout<<count<<endl;
  }
  
  
  
  

  
   
  return 0;
}