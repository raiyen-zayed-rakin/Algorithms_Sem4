#include<iostream>
#define l long
#define ll long long
using namespace std;

int gcd(ll u, ll v)
{
   ll temp;
   while(v!=0){
    temp = u%v;
    u = v;
    v = temp;
   }
   return u;
}

int main(){
l t;
cin>>t;
ll a, b;
for (l i = 0; i < t; i++)
{
  cin>>a>>b;
  //if((gcd(a,b) > 1) && )
}




return 0;
}