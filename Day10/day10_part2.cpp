#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{ 
    int signalStrength = 0;
    string instruction;
    int nb = 0;
    int score = 1; 
    int numCycle = 0;
    vector<char> res;
    int lowBound = 1;
    int highBound = 3;

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
               if ((numCycle-1) % 40 == 0){
                    numCycle = 1;
                }
                if (lowBound <= numCycle && numCycle <= highBound ){
                    res.push_back('#');
                }
                else{
                    res.push_back(' ');
                }
            }
            lowBound += nb;
            highBound += nb;
        }
        else{
            numCycle++;
            if ((numCycle-1) % 40 == 0){
                numCycle = 1;
            }
            if (lowBound <= numCycle && numCycle <= highBound ){
                res.push_back('#');
            }
            else{
                res.push_back(' ');
            }
        }
    }

    cout << res.size() << endl;
    for (int i=0;i<6;i++){
        for(int j=0;j<40; j++){
            cout << res[i*40+j] << " ";
        }
        cout << endl;
    }

}