#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



int main()
{
    string s;
    while(1){
        int index = 0;
        vector<char> digit;
        getline(cin, s);

        for (const auto & c : s) {
            digit.push_back(c);
            index++;
            vector<char> tmp = digit;
            sort(tmp.begin(), tmp.end());
            if (digit.size() == 14 && std::adjacent_find(tmp.begin(), tmp.end()) == tmp.end()){
                cout << index;
            }
            else if (digit.size() == 14){
                tmp.clear();
                digit.erase(digit.begin());
            }
        }

    }
}
