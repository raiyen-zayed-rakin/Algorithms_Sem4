/*
Suppose, you have to pay out an amount of 1887 taka to your friend and you have the following supply of notes: 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1. How will you pay back using least number of notes? Write a program to display the selected notes.
*/
#include<iostream>
using namespace std;
//manual/ greedy /O(n)
void selectedNotes(int ammount){
  int numOfNotes = 0;
  int Notes[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int selectedNote[10] = {0};
  int temp = ammount;
  while(temp != 0){
    if(temp >= 1000){
      temp -= 1000;
      selectedNote[0]++;
      numOfNotes++;
    }
    else if(temp >= 500){
      temp -= 500;
      selectedNote[1]++;
      numOfNotes++;
    }    
    else if(temp >= 200){
      temp -= 200;
      selectedNote[2]++;
      numOfNotes++;
    }    
    else if(temp >= 100){
      temp -= 100;
      selectedNote[3]++;
      numOfNotes++;
    }    
    else if(temp >= 50){
      temp -= 50;
      selectedNote[4]++;
      numOfNotes++;
    }    
    else if(temp >= 20){
      temp -= 20;
      selectedNote[5]++;
      numOfNotes++;
    }    
    else if(temp >= 10){
      temp -= 10;
      selectedNote[6]++;
      numOfNotes++;
    }    
    else if(temp >= 5){
      temp -= 5;
      selectedNote[7]++;
      numOfNotes++;
    }    
    else if(temp >= 2){
      temp -= 2;
      selectedNote[8]++;
      numOfNotes++;
    }
    else if(temp >= 1){
      temp -= 1;
      selectedNote[9]++;
      numOfNotes++;
    }
  }

  cout<<"Number of notes used : "<<numOfNotes<<endl;
  for (int i = 0; i < 10; i++)
  {
    cout<<"Number of "<<Notes[i]<<" bills used : "<<selectedNote[i]<<endl;
  }
  
}

//O(n^2)
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

void calculationSUM(int ammount){

}

int main(){
  int ammount;
  cout<<"Enter the ammount : ";
  cin>>ammount;
  selectedNotes(ammount);



  return 0;
}