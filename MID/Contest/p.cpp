#include<iostream>
#define l long
#define ll long long

using namespace std;

int main(){
int t;
cin>>t;
ll n;
for (int i = 0; i < t; i++)
{
  cin>>n;
  if((n % 2 == 0) || (n % 5 != 0)){
    cout<<0<<endl;
  }
}




return 0;
}