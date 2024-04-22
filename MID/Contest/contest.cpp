#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;



int main(){

  int t;
  cin>>t;

  while (t--)
  {
    int a,b,c;
    cin>>a>>b>>c;
    int maxi = max(max(a,b),c);

    if(maxi == a){
      if(a*a == (b*b + c*c)){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
    else if(maxi == b){
      if(b*b == (a*a + c*c)){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
    else if(maxi == c){
      if(c*c == (b*b + a*a)){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
  }
  

  return 0;
}