#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int LIMIT = 4000000;


set<pair<ll,ll>> fillPOssibleBeacon(vector<vector<ll>> sensorPos){

    set<pair<ll,ll>> possibleBeacon;

    for (int i =0; i<sensorPos.size(); i++){
        ll x = sensorPos[i][0];
        ll y = sensorPos[i][1];
        ll dst = sensorPos[i][2] + 1;

        for (int k=0; k< dst; k++){
            ll xOffset = k;
            ll yOffset = dst - k;
            if (x + xOffset >= 0 && x + xOffset <= LIMIT &&  y + yOffset >= 0 && y + yOffset <= LIMIT)
                possibleBeacon.insert(make_pair(x + xOffset, y + yOffset));
            if (x - xOffset >= 0 && x - xOffset <= LIMIT &&  y + yOffset >= 0 && y + yOffset <= LIMIT)
                possibleBeacon.insert(make_pair(x - xOffset, y + yOffset));
            if (x + xOffset >= 0 && x + xOffset <= LIMIT &&  y - yOffset >= 0 && y - yOffset <= LIMIT)
                possibleBeacon.insert(make_pair(x + xOffset, y - yOffset));
            if (x - xOffset >= 0 && x - xOffset <= LIMIT &&  y - yOffset >= 0 && y - yOffset <= LIMIT)
                possibleBeacon.insert(make_pair(x - xOffset, y - yOffset));
        }
    }

    return possibleBeacon;
}

int main() {

    std::ifstream file("day15.txt");
    set<ll> NotBeacon;
    set<ll> Beacon;

    set<pair<ll,ll>> possibleBeacon;
    set<pair<ll,ll>> diffPossible;
    vector<vector<ll>> sensorPos;

   int yAnswer = 2000000;
    // int yAnswer = 10;
    string str;
    int cntLine = 1;
    while (std::getline(file, str))
    {

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

        ll manatthanDistance = abs(x1 - x2) + abs(y1 - y2);

        vector<ll> tmp = {x1, y1, manatthanDistance};
        sensorPos.push_back(tmp);
    } 

    possibleBeacon = fillPOssibleBeacon(sensorPos);

    for (int j = 0; j < sensorPos.size(); j++){
        for (auto & elt : possibleBeacon){
            ll xPossible = elt.first;
            ll yPossible = elt.second;
            ll dst = abs(xPossible - sensorPos[j][0]) + abs(yPossible - sensorPos[j][1]); 
            if (dst <= sensorPos[j][2]) {
                if (xPossible >= 0 && xPossible <= LIMIT && yPossible >= 0 && yPossible <= LIMIT)
                    diffPossible.insert(make_pair(xPossible, yPossible));
            }
        }
    }

    std::set<pair<int,int>> result;
    std::set_difference(possibleBeacon.begin(), possibleBeacon.end(), diffPossible.begin(), diffPossible.end(),
        std::inserter(result, result.end()));

    ll res = 0;

    for (const auto & elt : result) {
        ll res = long(elt.first) * 4000000 + elt.second;
        cout << res << endl;
    }



}