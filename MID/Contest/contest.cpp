#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;



int main(){

  int t;
  cin>>t;

  while (t--)
  {
    int n;
    cin>>n;
    int arr[n];
    int res1 = 0;
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];
    }

    int freq[n] ={0};
    for(int i : arr){
      freq[i]++;
    }
    int mostF = 0;
    for(int cnt : freq){
      mostF = max(mostF, cnt);
    }
    int res = n - mostF;
    cout<<res<<endl;
  }
  

  return 0;
}