#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> heap = {
    "QSWCZVFT",
    "QRB",
    "BZTQPMS",
    "DVFRQH",
    "JGLDBSTP",
    "WRTZ",
    "HQMNSFRJ",
    "RNFHW",
    "JZTQPRB"
};

int main()
{
    string s;
    while(1){
        getline(cin, s);

        if (s != "ok"){

 
        s.erase(0, s.find(' ') + 1);
        std::string token1 = s.substr(0, s.find(' '));
        int nb = stoi(token1);

        s.erase(0, s.find(' ') + 1);
        s.erase(0, s.find(' ') + 1);
        std::string token2 = s.substr(0, s.find(' '));
        int from = stoi(token2);

        s.erase(0, s.find(' ') + 1);
        s.erase(0, s.find(' ') + 1);
        std::string token3 = s.substr(0, s.find(' '));
        int to = stoi(token3);

        std::vector<char> y(heap[from-1].end() - nb, heap[from-1].end());

        for (int i=0; i<nb; i++) {
            heap[from-1].pop_back();
        }
        for (const auto & elt : y)
            heap[to-1].push_back(elt);

        y.clear();

    }
    else{
        for (const auto & elt : heap)
            cout << elt.back();
    }


    }

    
}
