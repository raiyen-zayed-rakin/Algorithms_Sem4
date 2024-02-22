#include<iostream>
 
using namespace std;
 
class Student {
    public:
    string name;
    string id;
    int age;
    string department;
    float sgpa[2][2];
};
 
float calculateSGPA(float grades[], int numCourses) {
    float totalPoints = 0;
    for (int i = 0; i < numCourses; i++) {
        totalPoints+= grades[i];
    }
    return totalPoints/numCourses;
}
 
float calculateCGPA(Student students[], int currentSemester) {
    float totalSGPA = 0;
    for (int i = 0; i < currentSemester; i++) {
        totalSGPA += calculateSGPA(students[i].sgpa[i], 5);
    }
    return totalSGPA/currentSemester;
}
 
bool isEligibleForWaiver(float sgpa) {
    return sgpa >= 3.75;
}
 
int main() {
    Student students[2];
    for (int i = 0; i < 2; i++) {
        cout<<"For student "<<i + 1<<endl;
        cout<<"Enter Name: ";
        cin>>students[i].name;
        cout<<"Enter ID: ";
        cin>>students[i].id;
        cout<<"Enter Age: ";
        cin>>students[i].age;
        cout<<"Enter Department: ";
        cin>>students[i].department;
        for(int m = 0; m < 2; m++){
            cout << "Enter SGPA for Semester "<<m + 1<<endl;
            for (int n = 0; n < 2; n++) {
                cout<<"Enter grade for Course "<<n + 1 <<": ";
                cin>>students[i].sgpa[m][n];
            }
        }
        cout<<endl;
    }
    for (int i = 0; i < 2; i++) {
        float SGPA=calculateSGPA(students[i].sgpa[i], 5);
        float CGPA=calculateCGPA(students, i + 1);
        bool waiverEligibility=isEligibleForWaiver(SGPA);
        cout << "Student No."<<i + 1<<"-"<<students[i].name<<" - ID: "<<students[i].id<<endl;
        cout << "Current SGPA: " << SGPA << "\n";
        cout << "Current CGPA: " << CGPA << "\n";
        if(waiverEligibility){
          cout << "Eligible for 25% Waiver: Yes"<<endl<<endl;
        }
        else{
          cout << "Eligible for 25% Waiver: No"<<endl<<endl;  
        }
    }
 
    return 0;

}
