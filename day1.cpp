#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int max = 0;
    int localMax = 0;
    vector<string> vec;
    vector<int> vecStorageInt;
    while (1) {
        getline(cin, s);
        vec.push_back(s);
        if (s == "") {
            vecStorageInt.push_back(localMax);
            localMax = 0;
        }
        else if (s != "stop") {
            localMax += std::stoi(s);
        }
        else {
            std::sort(vecStorageInt.begin(),vecStorageInt.end(), greater<int>()); //Sorting the vector desc
            int res = 0;
            for (int i = 0; i < 3; i++){
                res += vecStorageInt[i];
            }
            cout << res;
        }
    }
    return 0;
}
