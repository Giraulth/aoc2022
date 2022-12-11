#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{ 
    vector<string> trees;
    vector<vector<bool>> isSean;
    vector<vector<int>> scenicScore;
    std::ifstream file("day8.txt");
    std::string str; 
    int width = 99;
    int height = 99;
    int res = 0;
    while (std::getline(file, str))
    {
        trees.push_back(str);
        vector<bool> tmp;
        vector<int> tmpScore;
        for (int i=0; i<height; i++){
            tmp.push_back(false);
            tmpScore.push_back(1);
        }
        isSean.push_back(tmp);
        scenicScore.push_back(tmpScore);
        tmp.clear();
        tmpScore.clear();
    }

    // view tree from left side
    for (int i = 0; i<width; i++){
        string studiedSide = trees[i];
        studiedSide.pop_back();
        
        // left side
        for (int j = 0; j<studiedSide.size(); j++) {
            if (j == 0 || j==studiedSide.size()-1){
                if (!isSean[i][j]){
                    res++;
                    isSean[i][j] = true;
                }
            }
            vector<int> part1;
            vector<int> part2;
            for (int k=0; k<j;k++){
                part1.push_back(stoi(std::string(1, studiedSide[k])));
            }
            for (int k=j+1; k<studiedSide.size();k++){
                part2.push_back(stoi(std::string(1, studiedSide[k])));
            }
            auto const max_iter1 = std::max_element(part1.begin(), part1.end());
            auto const max_iter2 = std::max_element(part2.begin(), part2.end());
            int max1 = 0;
            int max2 = 0;
            if (max_iter1 == part1.end())
                max1 = -1;
            else
                max1 = *max_iter1;
            if (max_iter2 == part2.end())
                max2 = -1;
            else
                max2 = *max_iter2;
            
            if (stoi(std::string(1, studiedSide[j])) > max1 || stoi(std::string(1, studiedSide[j])) > max2){
                if (!isSean[i][j]){
                    res++;
                    isSean[i][j] = true;
                }
            }
        }
    }

    // view tree from top side
    for (int i=0; i<height;  i++) {
        // build string from top side
        string studiedSide = "";
        for (int j=0; j<width; j++){
            studiedSide += trees[j][i];
        }

        //     top side
        for (int k = 0; k<studiedSide.size(); k++) {
            if (i== 0 || i==studiedSide.size()-1){
                if (!isSean[i][k]){
                    res++;
                    isSean[i][k] = true;
                }
            }
            vector<int> part1;
            vector<int> part2;
            for (int m=0; m<k;m++){
                part1.push_back(stoi(std::string(1, studiedSide[m])));
            }
            for (int m=k+1; m<studiedSide.size();m++){
                part2.push_back(stoi(std::string(1, studiedSide[m])));
            }
            auto const max_iter1 = std::max_element(part1.begin(), part1.end());
            auto const max_iter2 = std::max_element(part2.begin(), part2.end());
            int max1 = 0;
            int max2 = 0;
            if (max_iter1 == part1.end())
                max1 = -1;
            else
                max1 = *max_iter1;
            if (max_iter2 == part2.end())
                max2 = -1;
            else
                max2 = *max_iter2;
            if (stoi(std::string(1, studiedSide[k])) > max1 || stoi(std::string(1, studiedSide[k])) > max2){
                if (!isSean[k][i]){
                    res++;
                    isSean[k][i] = true;
                }
            }

        }
    }

        for (int i=1; i<width-1; i++){
            for (int j=1;j<width-1;j++){
                int tmp = 0;
                // right
                for(int k=j+1; k<width; k++ ){
                    if(trees[i][k] < trees[i][j])
                        tmp++;
                    else {
                        tmp++;
                        break;
                    }
                }
                scenicScore[i][j] *= tmp;
                tmp = 0;
                // left
                for(int k = j-1; k>=0; k--){
                if(trees[i][k] < trees[i][j])
                        tmp++;
                    else {
                        tmp++;
                        break;
                    }
                }
                scenicScore[i][j] *= tmp;
                tmp = 0;
                for(int k=i+1; k<width; k++ ){
                    if(trees[k][j] < trees[i][j])
                        tmp++;
                    else {
                        tmp++;
                        break;
                    }
                }
                scenicScore[i][j] *= tmp;
                tmp = 0;
                for(int k = i-1; k>=0; k--){
                if(trees[k][j] < trees[i][j])
                        tmp++;
                    else {
                        tmp++;
                        break;
                    }
                }
                scenicScore[i][j] *= tmp;
                }
        }

    cout << res << endl;
    int max = 0;

            for (int i=0; i<width; i++){
            for (int j=0;j<width;j++){
                if (scenicScore[i][j] > max)
                    max = scenicScore[i][j];
            }
        }

    cout << max;
}