#include <iostream>
#include <sstream>
using namespace std;

// Structure to hold hours and minutes
struct HoursAndMinutes {
    int hours;
    int minutes;
};

// Function to convert time to 12-hour notation
void convertToMeridiem(int hours, int minutes);

// Function to parse time input into hours and minutes
HoursAndMinutes parseTime(string time);

int main()
{
    int hours, mins;
    string time;

    // Welcome message
    cout << "Welcome to the 24-Hour to 12-Hour Notation Converter Program!" << endl;
    cout << "--------------------------------------------------------------" << endl << endl;

    // Prompt user for time input
    cout << "Please enter the time in 24-hour notation (hours and minutes): ";
    cin >> time;
    cout << endl;

    // Parse the time input
    HoursAndMinutes hAndS = parseTime(time);

    // Convert the parsed time to 12-hour notation
    convertToMeridiem(hAndS.hours, hAndS.minutes);

    return 0;
}

// Function to parse time input into hours and minutes
HoursAndMinutes parseTime(string time){
    stringstream ss(time);
    string hoursStr, minutesStr;
    int hours, minutes;
    HoursAndMinutes hAndS;

    // Extract hours and minutes from the time string using stringstream and getline
    getline(ss, hoursStr, ':');
    getline(ss, minutesStr);

    // Convert hours and minutes from string to integer using stringstream
    stringstream(hoursStr) >> hours;
    stringstream(minutesStr) >> minutes;

    // Store the parsed hours and minutes in the HoursAndMinutes structure
    hAndS.hours = hours;
    hAndS.minutes = minutes;

    return hAndS;
}

// Function to convert time to 12-hour notation
void convertToMeridiem(int hours, int minutes){

    // Adjust hours for 12-hour notation
    if (hours == 0) {
        hours = 12;
    } else if (hours > 12) {
        hours -= 12;
    }

    // Display the converted time in 12-hour notation
    cout << "The time in 12-hour notation is: " << hours << ":" << minutes;
}
