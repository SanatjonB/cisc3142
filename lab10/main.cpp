#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string id;
    string answers;
    int score;
    char grade;
};



char getGrade(double p) {
    if (p >= 90) return 'A';
    if (p >= 80) return 'B';
    if (p >= 70) return 'C';
    if (p >= 60) return 'D';
    return 'F';
}


int main() {
    ifstream data("data.txt");
    string answerKey;
    getline(data, answerKey);
    int size = 15;
    int count = 0;
    Student* students = new Student[size];
    while (!data.eof()) {


        if (count == size) {
            size *= 2;
            Student* temp = new Student[size];
            for (int i = 0; i < count; i++)
                temp[i] = students[i];
            delete[] students;
            students = temp;
        }
        data>>students[count].id;
        data.ignore();
        getline(data, students[count].answers);
        int score = 0;


        for (int i = 0; i < 20; i++) {
            if (students[count].answers[i] == ' ') continue;
            else if (students[count].answers[i] == answerKey[i]) score += 2;
            else score -= 1;
        }
        students[count].score = score;
        double percent = (score / 40.0) * 100;
        students[count].grade = getGrade(percent);
        count++;
    }

    
    for (int i = 0; i < count; i++) {
        cout<< students[i].id <<" "<<students[i].answers << " "<<students[i].score << " "<<students[i].grade <<endl;
    }
    //delete[] students; just curious if you see this 
    return 0;
}
