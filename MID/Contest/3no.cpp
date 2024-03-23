#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>

#define ll long long
using namespace std;



int main(){
  string s;
  cin>>s;

  stringstream ss(s);

  vector<ll> result;
  
  char ch;
  int n;
  while (ss >> n)
  {
    result.push_back(n);
    ss >> ch;
  }
  for (ll i = 0; i < result.size(); i++)
  {
    cout<<result[i]<<endl;
  }
  
   
  return 0;
}