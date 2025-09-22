// •	Process each student’s score:
// •	Use an if statement to check whether the student passed or failed.
// •	Passing = 60 and above
// •	Failing = below 60
// •	Use a switch-case to assign a letter grade based on the score:
// •	90–100 → A
// •	80–89 → B
// •	70–79 → C
// •	60–69 → D
// •	< 60 → F
// •	Output requirements:
// Print a formatted report to the console like this
// •	Each line of the file contains:
// 	ID FirstName LastName Score

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char getLetterGrade(int score);
int main(){
    ifstream inputFile; 
    ofstream outPutFile;
    string status;

    int id,score;
    string firstName, lastName;

    inputFile.open("students.txt");
    outPutFile.open("output.txt");

    while(inputFile>>id>>firstName>>lastName>>score){
        char grade = getLetterGrade(score);
        if(score>=60){
            status = "Pass";
        }
        else{
            status = "Fail";
        }
        outPutFile<<"ID: " <<id<<" | "<< "Name: "<<firstName<<" "<<lastName <<"  | Score: "<< score<<" | Grade: "<< grade << " | Status: "<< status << endl;
        cout<<"ID: " <<id<<" | "<< "Name: "<<firstName<<" "<<lastName <<"  | Score: "<< score<<" | Grade: "<< grade << " | Status: "<< status << endl;
        //format ID: 101 | Name: Alice Brown | Score: 87 | Grade: B | Status: Pass
    }

    return 0;
}

char getLetterGrade(int score){
    switch (score / 10) {
        case 10: 
        case 9:  return 'A';
        case 8:  return 'B'; 
        case 7:  return 'C'; 
        case 6:  return 'D'; 
        default: return 'F'; 
    }
}