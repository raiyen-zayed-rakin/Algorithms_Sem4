/*
Write a program to store name, NID, age, occupation, account balance of 5 customers. They have taken loan from a bank (3000000, 5000000, 7500000, 6000000,13000000) Taka  with 13.5%monthly interest on their loan. Now, calculate the annual amount and amount after 10 years  and display as an output. 
*/

#include<iostream>

using namespace std;

class Customer{
  public: 
  string name;
  int nid;
  int age;
  string occupation;
  double balance;
  double loan;
};

void calculateAmmount(Customer customers[],int no, int year){
  int total=0;
  cout<<"Name : "<<customers[no].name<<endl;
  cout<<"NID : "<<customers[no].nid<<endl;
  cout<<"Age : "<<customers[no].age<<endl;
  cout<<"Occupation : "<<customers[no].occupation<<endl;
  cout<<"Balance : "<<customers[no].balance<<endl;
  cout<<"loan : "<<customers[no].loan<<endl;
  for ( int i = 1; i <= 12; i++)
  {
    total= total + 0.135*customers[no].loan;  
  }
  cout<<endl;
  cout<<"Annual ammount : "<<total<<" Taka"<<endl;
  cout<<"Amount after "<<year<<" years : "<<(customers[no].loan+total)*10<<" Taka"<<endl;
  return ;
}
int main(){
  int n;
  cout<<"Enter the number of customers : ";
  cin>>n;

  Customer customers[n];

  for (int i = 0; i < n; i++)
  {
    cout<<"For customer no."<<i+1<<" : "<<endl;
    cout<<"Enter Name : ";
    cin>>customers[i].name;
    cout<<"Enter nid : ";
    cin>>customers[i].nid;
    cout<<"Enter age : ";
    cin>>customers[i].age;
    cout<<"Enter occupation : ";
    cin>>customers[i].occupation;
    cout<<"Enter balance : ";
    cin>>customers[i].balance;
    cout<<"Enter loan : ";
    cin>>customers[i].loan;
  }
  cout<<endl<<endl;

  for (int i = 0; i < n; i++)
  {
    cout<<"Customer No."<<i+1<<" info with annual ammount and ammount after 10 years : "<<endl;
    calculateAmmount(customers, i, 10);
  }
  
  
  return 0;
}