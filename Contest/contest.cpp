#include<iostream>
#include<algorithm>
using namespace std;


void A(int a, int b){
  for (int i = a; i <= b; i++)
  {
    if(i == 1){
      cout<<"one"<<endl;
    }
    else if(i == 2){
      cout<<"two"<<endl;
    }
    else if(i == 3){
      cout<<"three"<<endl;
    }
    else if(i == 4){
      cout<<"four"<<endl;
    }
    else if(i == 5){
      cout<<"five"<<endl;
    }
    else if(i == 6){
      cout<<"six"<<endl;
    }
    else if(i == 7){
      cout<<"seven"<<endl;
    }
    else if(i == 8){
      cout<<"eight"<<endl;
    }
    else if(i == 9){
      cout<<"nine"<<endl;
    }

    if(i > 9){
      if(i % 2 == 0){
        cout<<"even"<<endl;
      }
      else{
        cout<<"odd"<<endl;
      }
    }
  }
  
}

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