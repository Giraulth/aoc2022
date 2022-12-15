#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTouching(int head_x, int head_y, int tail_x, int tail_y){
    if (abs(head_x-tail_x)<=1 && abs(head_y-tail_y)<=1){
        return true;
    }
    return false;
}

int main() 
{ 
    string moove;
    int nb;

    int head_x = 0;
    int head_y = 0;
    int tail_x = 0;
    int tail_y = 0;
    vector<pair<int,int>> position;
    set<pair<int,int>> tailPosition;

    for (int i=0;i<10;i++){
        auto p2 = std::make_pair(0, 0);
        position.push_back(p2);
    }

    std::ifstream file("day9.txt");
    string str;
    while (std::getline(file, str))
    {
        moove = str.substr(0, str.find(' '));
        str.erase(0, str.find(' ') + 1);
        nb = stoi(str);

        for (int i=0; i<nb; i++){
            if (moove == "R"){
                position[0].first++;
            }
            else if (moove == "D"){
                position[0].second--;
            }
            else if (moove == "U"){
                position[0].second++;
            }
            else if (moove == "L"){
                position[0].first--;
            }

            for (int j=0; j<9; j++){

                head_x = position[j].first;
                tail_x = position[j+1].first;
                head_y = position[j].second;
                tail_y = position[j+1].second;

            if(!isTouching(head_x, head_y, tail_x, tail_y)){
                // moove to touch
                if (head_x==tail_x){
                    if(head_y>tail_y){
                        tail_y++;
                    }
                    else{
                        tail_y--;
                    }
                }
                else if(head_y==tail_y){
                    if(head_x>tail_x){
                        tail_x++;
                    }
                    else{
                        tail_x--;
                    }
                }
                else{
                    // diagonaly
                    if (head_x>tail_x && head_y<tail_y){
                        tail_x++;
                        tail_y--;
                    }
                    if (head_x>tail_x && head_y>tail_y){
                        tail_x++;
                        tail_y++;
                    }
                    if (head_x<tail_x && head_y<tail_y){
                        tail_x--;
                        tail_y--;
                    }
                    if (head_x<tail_x && head_y>tail_y){
                        tail_x--;
                        tail_y++;
                    }
                }
                position[j].first = head_x;
                position[j+1].first = tail_x;
                position[j].second = head_y;
                position[j+1].second = tail_y;
            }
            else {
                break;
            }
            }

            auto p2 = std::make_pair(position[9].first, position[9].second);
            tailPosition.insert(p2);
        }
    }

    cout << tailPosition.size() << endl;

}