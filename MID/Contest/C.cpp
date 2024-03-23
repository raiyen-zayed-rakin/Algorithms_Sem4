#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
  int a,b,c,d;
  for (int i = 0; i < t; i++)
  {
    cin>>a>>b>>c>>d;
    int arr[4] = {a, b, c, d};
    
    sort(arr, arr+4);
    a = arr[1];
    b = arr[2];
    c = arr[3];
    double s = 0.0; 
    s = (double)(a+b+c) / 2;
    
    double area = sqrt(s *(s-a) * (s-b) * (s-c));
    cout<<fixed<<setprecision(2)<<area<<endl;
  }
  

	
  return 0;
}