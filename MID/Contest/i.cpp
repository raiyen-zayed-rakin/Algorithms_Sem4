#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>

#define ll long long
using namespace std;



int main(){
  int t;
  cin>>t;
  int n, m, k;
  for (int i = 0; i < t; i++)
  {
    cin>>n>>m>>k;
    if((m-k) >= n){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  
  
   
  return 0;
}