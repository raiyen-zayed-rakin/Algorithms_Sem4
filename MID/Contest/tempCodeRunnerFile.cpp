#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>

#define ll long long
using namespace std;



int main(){
  int t;
  cin>>t;
  int x, y;
  for (int i = 0; i < t; i++)
  {
    cin>>x>>y;
    if(x == y){
      cout<<"ANY"<<endl;
    }
    else if(x > y){
      cout<<"SECOND"<<endl;
    }
    else{
      cout<<"FIRST"<<endl;
    }
  }
  
  
   
  return 0;
}