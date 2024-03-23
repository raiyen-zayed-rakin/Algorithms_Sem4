#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
double maxTriangleArea(double A, double B, double C, double D) {
    double sides[] = {A, B, C, D};
    double maxArea = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                double a = sides[i];
                double b = sides[j];
                double c = sides[k];
                double s = (a + b + c) / 2;
                double area = sqrt(s * (s - a) * (s - b) * (s - c));
                maxArea = std::max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main() {
    int t;
  std::cin>>t;

  while (t--)
  {
    double A;
    double B ;
    double C ;
    double D ;
    std::cin>>A>>B>>C>>D;
    std::cout << "Maximum area of triangle with sides " << A << ", " << B << ", " << C << ", " << D << " is: "<<fixed<<setprecision(2)<<
              maxTriangleArea(A, B, C, D) << std::endl;
    
  }return 0;
}
