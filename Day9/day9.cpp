#include <fstream>
#include <string>
#include <set>
#include <iostream>
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
    set<pair<int,int>> tailPosition;

    std::ifstream file("day9.txt");
    string str;
    while (std::getline(file, str))
    {
        moove = str.substr(0, str.find(' '));
        str.erase(0, str.find(' ') + 1);
        nb = stoi(str);

        for (int i=0; i<nb; i++){
            if (moove == "R"){
                head_x++;
            }
            else if (moove == "D"){
                head_y--;
            }
            else if (moove == "U"){
                head_y++;
            }
            else if (moove == "L"){
                head_x--;
            }

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
            }

            auto p2 = std::make_pair(tail_x, tail_y);
            tailPosition.insert(p2);
        }
    }

    cout << tailPosition.size() << endl;

}