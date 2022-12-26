#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {

    std::ifstream file("day14.txt");
    int N = 2000;
    int M = 173;
    int xOffset=300;

    string str;
    vector<vector<bool>> isVisited;
    vector<pair<int, int>> positions;
    for(int i=0;i<M;i++){
        vector<bool> tmp;
        for(int j=0;j<N;j++){
            tmp.push_back(false);
        }
        isVisited.push_back(tmp);
    }
    while (std::getline(file, str))
    {
        vector<string> v = split (str, " -> ");
        for (int k = 0; k < v.size() - 1; k++){
            int x1 = stoi(split(v[k], ",")[0])-xOffset;
            int y1 = stoi(split(v[k], ",")[1]);
            int x2 = stoi(split(v[k+1], ",")[0])-xOffset;
            int y2 = stoi(split(v[k+1], ",")[1]);
            // fill map
            for(int i=y1;i<=y2;i++){
                for(int j=x1;j<=x2;j++){
                    isVisited[i][j]=true;
                }
            }
            for(int i=y1;i<=y2;i++){
                for(int j=x1;j>=x2;j--){
                    isVisited[i][j]=true;
                }
            }
            for(int i=y1;i>=y2;i--){
                for(int j=x1;j>=x2;j--){
                    isVisited[i][j]=true;
                }
            }
            for(int i=y1;i>=y2;i--){
                for(int j=x1;j<=x2;j++){
                    isVisited[i][j]=true;
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        isVisited[M-1][i] = (true);
    }

    bool stop=false;
    int size=0;
    for(int k=0;k<1000000;k++){
        int y = 500 -xOffset;
        for(int i=0;i<M-1;i++){
            if(!isVisited[i+1][y]){
    
            }
            else if (!isVisited[i+1][y-1]){
                y = y-1;
                if (y==0 || y==N-1)
                    stop=true;
            }
            else if (!isVisited[i+1][y+1]){
                y = y+1;
            }
            else{
                size++;
                isVisited[i][y] = true;
                if (isVisited[0][500-xOffset]){
                    cout << size << endl;
                    return 0;

                }
                break;
            }
        }
        
    }

                    for (int i=0;i<M;i++){
                        for(int j=0;j<N;j++){
                            if (isVisited[i][j])
                                cout << "#";
                            else
                                cout << " ";
                        }
                        cout << endl;
                    }


    return 0;
}