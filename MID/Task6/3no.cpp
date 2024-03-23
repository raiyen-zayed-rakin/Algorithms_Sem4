/*
Mithu has 6 Jars of biscuits. He wants to do a biscuit party with his friends. But he can take it according to his bag capacity (max capacity, W=15). Which algorithm will he apply for maximizing the taste value?  Write a program to implement it. 

Jar No:               1        2        3        4        5       6 
weight(w):            3        1        2        4        5       6 
TasteValue(v):        2        4        5        5        7       8  
*/

#include<iostream>

using namespace std;

class Jar{
  public:
  int no;
  int weight;
  int TasteValue;
  float pervalue;
};

int main(){
  int W = 15;
  int numOfJar = 6;
  Jar jars[numOfJar] = {
    {1, 3, 2, 0.0},
    {2, 1, 4, 0.0},
    {3, 2, 5, 0.0},
    {4, 4, 5, 0.0},
    {5, 5, 7, 0.0},
    {6, 6, 8, 0.0},
  };

  for (int i = 0; i < numOfJar; i++)
  {
    jars[i].pervalue = (float)jars[i].TasteValue / jars[i].weight;
  }
  for (int i = 0; i < numOfJar; i++)
  {
    for (int j = i+1; j < numOfJar; j++)
    {
      if(jars[i].pervalue < jars[j].pervalue){
        Jar tempJar = jars[i];
        jars[i] = jars[j];
        jars[j] = tempJar;
      }
    }
  }
  
  double totalWeight = 0.0;
  double totalTasteValue = 0.0;

  cout<<"Final Selected Jars:"<<endl;

  for (int i = 0; i < numOfJar; i++)
  {
    if(totalWeight + jars[i].weight <= W){
      cout<<"Jar no."<<jars[i].no<<" -- Taste Value: "<<jars[i].TasteValue<<endl;
      totalWeight += jars[i].weight;
      totalTasteValue += jars[i].TasteValue;
    }
    else{
      double remW = W - totalWeight;
      double frac = remW / jars[i].weight;

      cout<<"Jar no."<<jars[i].no<<" -- Taste Value: "<<frac * jars[i].TasteValue<<"(Fractional)"<<endl;
      totalWeight += remW;
      totalTasteValue += frac * jars[i].TasteValue;
      break;
    }
  }
  
  cout<<"Total Taste Value: "<<totalTasteValue<<endl;
  cout<<"Total Weight: "<<totalWeight<<endl;
  
  return 0;
}