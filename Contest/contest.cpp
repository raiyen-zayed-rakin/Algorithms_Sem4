#include<iostream>
#include<algorithm>
using namespace std;



void B(string a, string b){
  cout<<a.length()<<" "<<b.length()<<endl;

  cout<<a+b<<endl;
  char temp = a[0];
  a[0] = b[0];
  b[0] = temp;
  cout<<a<<" "<<b<<endl;
}

int main(){
  string a, b;
  cin>>a>>b;

  B(a,b);

  return 0;
}