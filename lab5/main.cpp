#include <iostream>
using namespace std;

enum objectType { ROCK, PAPER, SCISSORS };

void displayRules();

objectType retrievePlay(char selection);

bool validSelection(char selection);

bool validYesNo(char choice); 

void convertEnum(objectType object);

objectType winningObject(objectType play1, objectType play2);

void gameResult(objectType play1, objectType play2, int &winner);

void displayResults(int gCount, int wCount1, int wCount2);

int main() {
    char again, p1ChoiceChar, p2ChoiceChar;
    objectType p1Play, p2Play;
    int totalGames = 0, p1Wins = 0, p2Wins = 0, winner;

    displayRules();

    cout << "Do you want to play Rock, Paper, Scissors? Y/y N/n: ";
    cin >> again;


    while (!validYesNo(again)) {
        cout << "Invalid input. Please enter Y/y or N/n: ";
        cin >> again;
    }

    while (again == 'Y' || again == 'y') {
        cout << "Player 1 - Enter R/r for Rock, P/p for Paper, S/s for Scissors: ";
        cin >> p1ChoiceChar;

        while (!validSelection(p1ChoiceChar)) {
            cout << "Invalid -- Enter R/r for Rock, P/p for Paper, S/s for Scissors:: ";
            cin >> p1ChoiceChar;
        }

        p1Play = retrievePlay(p1ChoiceChar);

        cout << "Player 2 - Enter R/r for Rock, P/p for Paper, S/s for Scissors: ";
        cin >> p2ChoiceChar;

        while (!validSelection(p2ChoiceChar)) {
            cout << "Invalid--Enter R/r for Rock, P/p for Paper, S/s for Scissors:: ";
            cin >> p2ChoiceChar;
        }

        p2Play = retrievePlay(p2ChoiceChar);

        gameResult(p1Play, p2Play, winner);

        totalGames++;

        if (winner == 1)
            p1Wins++;
        else if (winner == 2)
            p2Wins++;

        cout << "Play another round? Y/y N/n: ";
        cin >> again;


        while (!validYesNo(again)) {
            cout << "Invalid input. Please enter Y/y or N/n: ";
            cin >> again;
        }
    }

    displayResults(totalGames, p1Wins, p2Wins);

    return 0;
}

void displayRules() {
    cout << "Rock beats Scissors " << endl;
    cout << "Paper beats Rock" << endl;
    cout << "Scissors beat PAPER" << endl;
    cout << "Enter R for Rock, P for Paper, S for Scissors" << endl;
    cout << "Two players will enter their choices each round" << endl;
    cout << "Game tracks wins until you choose to stop" << endl;
}

bool validSelection(char selection) {
    return (selection == 'R' || selection == 'r' ||
            selection == 'P' || selection == 'p' ||
            selection == 'S' || selection == 's');
}


bool validYesNo(char choice) {
    return (choice == 'Y' || choice == 'y' ||
            choice == 'N' || choice == 'n');
}

objectType retrievePlay(char selection) {
    if (selection == 'R' || selection == 'r')
        return ROCK;
    else if (selection == 'P' || selection == 'p')
        return PAPER;
    else
        return SCISSORS;
}

void convertEnum(objectType object) {
    if (object == ROCK)
        cout << "Rock";
    else if (object == PAPER)
        cout << "Paper";
    else
        cout << "Scissors";
}

objectType winningObject(objectType play1, objectType play2) {
    if (play1 == play2)
        return play1;

    if (play1 == ROCK && play2 == SCISSORS) return ROCK;
    if (play2 == ROCK && play1 == SCISSORS) return ROCK;
    if (play1 == PAPER && play2 == ROCK) return PAPER;
    if (play2 == PAPER && play1 == ROCK) return PAPER;

    return SCISSORS;
}

void gameResult(objectType play1, objectType play2, int &winner) {
    cout << "Player 1 chose ";
    convertEnum(play1);
    cout << "Player 2 chose ";
    convertEnum(play2);

    if (play1 == play2) {
        cout << "Result: It's a tie. "<<endl;
        winner = 0;
        return;
    }

    objectType winObj = winningObject(play1, play2);

    if (winObj == play1 && winObj != play2) {
        cout << "Result: Player 1 wins this round" << endl;
        winner = 1;
    } else if (winObj == play2 && winObj != play1) {
        cout << "Result: Player 2 wins this round" << endl;
        winner = 2;
    } else {
        winner = 0;
    }
}

void displayResults(int gCount, int wCount1, int wCount2) {
    cout << "_________________ FINAL RESULTS _________________" << endl;
    cout << "Total rounds played: " << gCount << endl;
    cout << "Player 1 wins: " << wCount1 << endl;
    cout << "Player 2 wins: " << wCount2 << endl;
    cout << "______________________________________________________";
}
