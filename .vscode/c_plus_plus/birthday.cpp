#include <iostream>

 using namespace std;

 int calculateAge(int birthMonth, int birthDay, int birthYear, int currentMonth, int currentDay, int currentYear) {

    int age ;
    age= currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age ;
 }
 int main (){
    int age ;
    int birthMonth,birthDay,birthYear,currentMonth,currentDay,currentYear;
    cout << " Enter your birth month: ";
    cin >> birthMonth;
    cout << " Enter your birth day: ";
    cin >> birthDay;
    cout << " Enter your birth year: ";
    cin >> birthYear;
    cout << " Enter current month: ";
    cin >> currentMonth;
    cout << " Enter current day: ";
    cin >> currentDay;
    cout << " Enter current year: ";
    cin >> currentYear;
    
    cout << " Your age now " << age << " year/s old." << endl;

    
    return 0;
 }