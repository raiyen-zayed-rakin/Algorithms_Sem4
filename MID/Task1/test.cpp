#include<iostream>
using namespace std;
float cg=0;
bool check=false;
void  countcg(float mark){

    if (mark >= 90 && mark<=100) {
        cg+=4;
        }
    else if (mark >= 85) {
        cg+=3.75;
        }
    else if (mark >= 80) {
        cg+=3.50;
    } else if (mark >= 75) {
        cg+=3.25;
    } else if (mark >= 70) {
        cg+=3.00;
    }else if (mark >= 65) {
        cg+=2.75;
    }else if (mark >= 60) {
        cg+=2.50;
    }else if (mark >= 55) {
        cg+=2.25;
    } else {
        check=true;
    }

}
float getcg(){
    cout<<"Your Cgpa -> "<<cg/8<<endl;

if (check) cout << "You have failed in one or more courses." << endl;


}
int main(){
    float mark[8];
cout<<"Enter Marks"<<endl;
float total=0;
for(int i=0; i<8; i++){
    cout<<"Mark of course "<<i+1<<" -> ";
    cin>>mark[i];

    while (mark[i] < 0 || mark[i] > 100) {
        cout << "Invalid input. Please enter a mark between 0 and 100: ";
        cin >> mark[i];
        }

    total+=mark[i];
    countcg(mark[i]);
}
cout<<"\nTotal marks of 8 courses -> "<<total<<endl;
getcg();

return 0;
}
