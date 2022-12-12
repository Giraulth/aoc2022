#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{ 
    int signalStrength = 0;
    string instruction;
    int nb = 0;
    int score = 1; 
    int numCycle = 0;

    std::ifstream file("day10.txt");
    string str;
    while (std::getline(file, str))
    {
        instruction = str.substr(0, str.find(' '));
        if (instruction == "addx"){
            str.erase(0, str.find(' ') + 1);
            nb = stoi(str);
        }

        if (instruction == "addx") {
            for (int i=0;i<2;i++){
                numCycle ++;
                if (numCycle == 20 || (numCycle - 20) % 40 == 0){
                    cout << "score :" << score << " numCycle : " << numCycle << endl;
                    signalStrength += score * numCycle;
                }
            }
            score += nb;
        }
        else{
            numCycle++;
            if (numCycle == 20 || (numCycle - 20) % 40 == 0){
                cout << "score :" << score << " numCycle : " << numCycle << endl;
                signalStrength += score * numCycle;
            }
        }
    }

    cout << signalStrength << endl;

}