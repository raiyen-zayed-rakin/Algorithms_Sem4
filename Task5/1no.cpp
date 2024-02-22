/*
Suppose, you have to pay out an amount of 1887 taka to your friend and you have the following supply of notes: 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1. How will you pay back using least number of notes? Write a program to display the selected notes.
*/
#include<iostream>

using namespace std;

void selectedNotes(int ammount){
  int numOfNotes = 0;
  int selectedNote[10] = {0};
  int temp;
  while(temp >= 0){
    temp = ammount;
    if(temp % 1000 == 0){
      temp -= 1000;
      selectedNote[0]++;
      numOfNotes++;
    }
    else if(temp % 500 == 0){
      temp -= 500;
      selectedNote[1]++;
      numOfNotes++;
    }    
    else if(temp % 200 == 0){
      temp -= 200;
      selectedNote[2]++;
      numOfNotes++;
    }    
    else if(temp % 100 == 0){
      temp -= 100;
      selectedNote[3]++;
      numOfNotes++;
    }    
    else if(temp % 50 == 0){
      temp -= 50;
      selectedNote[4]++;
      numOfNotes++;
    }    
    else if(temp % 20 == 0){
      temp -= 20;
      selectedNote[5]++;
      numOfNotes++;
    }    
    else if(temp % 10 == 0){
      temp -= 10;
      selectedNote[6]++;
      numOfNotes++;
    }    
    else if(temp % 5 == 0){
      temp -= 5;
      selectedNote[7]++;
      numOfNotes++;
    }    
    else if(temp % 2 == 0){
      temp -= 2;
      selectedNote[8]++;
      numOfNotes++;
    }
  }

  cout<<"Number of notes used : "<<numOfNotes<<endl;
  cout<<"Number of 1000 bills used : "<<selectedNote[0]<<endl;
  cout<<"Number of 500 bills used : "<<selectedNote[1]<<endl;
  cout<<"Number of 200 bills used : "<<selectedNote[2]<<endl;
  cout<<"Number of 100 bills used : "<<selectedNote[3]<<endl;
  cout<<"Number of 50 bills used : "<<selectedNote[4]<<endl;
  cout<<"Number of 20 bills used : "<<selectedNote[5]<<endl;
  cout<<"Number of 10 bills used : "<<selectedNote[6]<<endl;
  cout<<"Number of 5 bills used : "<<selectedNote[7]<<endl;
  cout<<"Number of 2 bills used : "<<selectedNote[8]<<endl;
}

void calculatedSum(int ammount){
  int s = ammount;
  int ammountNote = 0;
  int Notes[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int NumOfNote[10] = {0};
  int i = 0;
  for (int i = 0; s != 0; i++)
  {  
    while (s >= Notes[i])
    {
      NumOfNote[i]++;
      ammountNote++;
      s = s - Notes[i];
    }  
  }
  
  cout<<"Number of Notes : "<<ammountNote<<endl;
  for (int i = 0; i < 10; i++)
  {
    cout<<"Number of "<<Notes[i]<<" bills used : "<<NumOfNote[i]<<endl;
    
  }

}

int main(){
  int ammount = 1887;
  calculatedSum(ammount);
  return 0;
}