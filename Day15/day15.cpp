#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

int main() {

    std::ifstream file("day15.txt");
    set<ll> NotBeacon;
    set<ll> Beacon;

   int yAnswer = 2000000;
    // int yAnswer = 10;
    string str;
    int cntLine = 1;
    while (std::getline(file, str))
    {

        cout << "Line " << cntLine << endl;
        cntLine++;
        std::string x1_str = str.substr(0, str.find('='));
        str.erase(0, str.find("=") + 1);
        x1_str = str.substr(0, str.find(','));
        str.erase(0, str.find(",") + 1);

        std::string y1_str = str.substr(0, str.find('='));
        str.erase(0, str.find("=") + 1);
        y1_str = str.substr(0, str.find(','));
        str.erase(0, str.find(":") + 1);

        std::string x2_str = str.substr(0, str.find('='));
        str.erase(0, str.find("=") + 1);
        x2_str = str.substr(0, str.find(','));
        str.erase(0, str.find(",") + 1);

        std::string y2_str = str.substr(0, str.find('='));
        str.erase(0, str.find("=") + 1);
        y2_str = str.substr(0, str.find(','));
        str.erase(0, str.find("\n") + 1);

        ll x1 = stoi(x1_str);
        ll y1 = stoi(y1_str);
        ll x2 = stoi(x2_str);
        ll y2 = stoi(y2_str);

        int manatthanDistance = abs(x1 - x2) + abs(y1 - y2);

        if (x2 == yAnswer)
            Beacon.insert(y2);

        ll xLimit = 0;
        ll yLimit = 0;

        int dst = abs(y1 - yAnswer);
        for (ll j= x1 - manatthanDistance + dst; j< x1 + manatthanDistance - dst; j++){
            NotBeacon.insert(j);
        }
    }        
    
    cout << (NotBeacon.size() - Beacon.size()) << endl;
}