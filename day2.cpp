#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<char, char> winnerMap = {
    {'X', 'Z'},
    {'Y', 'X'},
    {'Z', 'Y'}
};

map<char, char> looserMap = {
    {'Z', 'X'},
    {'X', 'Y'},
    {'Y', 'Z'}
};

map<char, char> conversionMap = {
    {'A', 'X'},
    {'B', 'Y'},
    {'C', 'Z'}
};

map<string, int> gameScore = {
    {"draw", 3},
    {"win", 6},
    {"loose", 0}
};

map<char, int> bonusScore = {
    {'X', 1},
    {'Y', 2},
    {'Z', 3}
};



int main()
{
    char adversary, convertedAdversary, me;
    int score = 0;
    while (1) {
        cin >> adversary >> me;
        if (adversary == 'o')
            cout << score;
        convertedAdversary = conversionMap[adversary];
        if (me == 'Y')
            me = convertedAdversary;
        else if (me == 'Z')
            me = looserMap[convertedAdversary];
        else if (me == 'X')
            me = winnerMap[convertedAdversary];

        if (convertedAdversary == me) {
            score += gameScore["draw"];
        }
        else if (winnerMap[me] == convertedAdversary) {
            score += gameScore["win"];
        }
        else if (winnerMap[me] != convertedAdversary) {
            score += gameScore["loose"];
        }
        score += bonusScore[me];
    }

}