#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double maxTriangleArea(double A, double B, double C, double D) {
    double sides[] = {A, B, C, D};
    double maxArea = 0;

    // Sort the sides
    std::sort(sides, sides + 4);

    // Exclude the smallest side
    for (int i = 1; i < 4; ++i) {
        double a = sides[i];
        double b = sides[(i + 1) % 4];
        double c = sides[(i + 2) % 4];
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        maxArea = std::max(maxArea, area);
    }

    return maxArea;
}

int main() {
  int t;
  cin>>t;

  while (t--)
  {
    double A;
    double B ;
    double C ;
    double D ;
    cin>>A>>B>>C>>D;
    std::cout << "Maximum area of triangle with sides " << A << ", " << B << ", " << C << ", " << D << " is: "
              << maxTriangleArea(A, B, C, D) << std::endl;
    
  }
  
    return 0;
}
