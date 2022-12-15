#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    vector<int> vec1;
    vector<int> vec2;
    vector<int> intersection;
    int res = 0;
    while (1) {

        string s;
        getline(cin, s);

        std::string token1 = s.substr(0, s.find('-'));
        s.erase(0, s.find("-") + 1);
        std::string token2 = s.substr(0, s.find(','));
        s.erase(0, s.find(",") + 1);
        std::string token3 = s.substr(0, s.find('-')); 
        s.erase(0, s.find("-") + 1);

        int a = stoi(token1);
        int b = stoi(token2);
        int c = stoi(token3);
        int d = stoi(s);

        for (int i=a; i<=b; i++)
            vec1.push_back(i);
        for (int i=c; i<=d; i++)
            vec2.push_back(i);

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
    
        std::set_intersection(vec1.begin(), vec1.end(),
                            vec2.begin(), vec2.end(),
                            std::back_inserter(intersection));

        if (intersection.size() > 0)
            res++;

        cout << res;

        vec1.clear();
        vec2.clear();
        intersection.clear();
        

    }
    return 0;
}
