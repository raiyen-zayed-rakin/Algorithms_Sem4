#include <iostream>
using namespace std;

void ResultLeapYear(int startYear, int endYear)
{

  bool leapYearFound = false;

  cout << "Leap years between " << startYear << " and " << endYear << " are: ";
  for (int year = startYear; year <= endYear; ++year)
  {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
      cout << year << " ";
      leapYearFound = true;
    }
  }
  if (!leapYearFound)
  {
    cout << "No leap year found.";
  }
  cout << endl;
}
int main()
{
  int startYear, endYear;

  cout << "Enter the start year: ";
  cin >> startYear;

  cout << "Enter the end year: ";
  cin >> endYear;

  if (startYear > endYear)
  {
    cout << "Invalid input." << endl;
    return 1;
  }

  ResultLeapYear(startYear, endYear);

  return 0;
}
