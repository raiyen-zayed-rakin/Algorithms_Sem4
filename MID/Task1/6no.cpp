#include<iostream>

using namespace std;
class SubsInfo{
  public:
  float marks;
  int credit;
};

void displayGrades(SubsInfo subs[], int size){
  float total = 0;
  int totalCredits = 0;
  for (int i = 0; i < size; i++)
  {
    if(subs[i].marks >= 90 && subs[i].marks<=100){
      cout<<"Subject No."<<i+1<<" grade is : A+(4.00)"<<endl;
      total += (subs[i].credit * 4.00); 
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 90 && subs[i].marks >= 85){
      cout<<"Subject No."<<i+1<<" grade is : A"<<endl;
      total += (subs[i].credit * 3.75); 
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 85 && subs[i].marks >= 80){
      cout<<"Subject No."<<i+1<<" grade is : B+"<<endl;
      total += (subs[i].credit * 3.50); 
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 80 && subs[i].marks >= 75){
      cout<<"Subject No."<<i+1<<" grade is : B"<<endl;
      total += (subs[i].credit * 3.25); 
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 75 && subs[i].marks >= 70){
      cout<<"Subject No."<<i+1<<" grade is : C+"<<endl;
      total += (subs[i].credit * 3.00); 
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 70 && subs[i].marks >= 65){
      cout<<"Subject No."<<i+1<<" grade is : C"<<endl;
      total += (subs[i].credit * 2.75); 
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 65 && subs[i].marks >= 60){
      cout<<"Subject No."<<i+1<<" grade is : D+"<<endl;
      total += (subs[i].credit * 2.50);  
      totalCredits += subs[i].credit;
    }
    else if(subs[i].marks < 60 && subs[i].marks >= 50){
      cout<<"Subject No."<<i+1<<" grade is : D+"<<endl;
      total += (subs[i].credit * 2.25); 
      totalCredits += subs[i].credit; 
    }
    else if(subs[i].marks < 50){
      cout<<"Subject No."<<i+1<<" grade is : F"<<endl;
      total += (subs[i].credit * 0.00); 
      totalCredits += subs[i].credit; 
    }
  }
    float result = total/totalCredits;
    cout<<"Total CGPA of 8 subjects : "<<result<<endl;
}

int main(){

  //made with class to store credit and calculate CGPA accurately
  SubsInfo subs[8];

  for (int i = 0; i < 8; i++)
  {
    cout<<"Enter the marks for the "<<i+1<<"th subject : ";
    cin>>subs[i].marks;
    cout<<"Enter the credits for the "<<i+1<<"th subject : ";
    cin>>subs[i].credit;

    cout<<endl<<endl;
  }
  
  displayGrades(subs, 8);



  return 0;
}