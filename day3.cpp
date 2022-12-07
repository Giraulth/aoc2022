#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    vector<char> vec1;
    vector<char> vec2;
    vector<char> vec3;
    vector<char> vec2_tmp;
    vector<char> res;
    int sum = 0;
    while (1) {

        getline(cin, s);
        for (const char & elt : s)
            vec1.push_back(elt);
        getline(cin, s);
        for (const char & elt : s)
            vec2.push_back(elt);
        getline(cin, s);
        for (const char & elt : s)
            vec3.push_back(elt);


        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        sort(vec3.begin(), vec3.end());
    
        std::set_intersection(vec1.begin(), vec1.end(),
                            vec2.begin(), vec2.end(),
                            std::back_inserter(vec2_tmp));

        sort(vec2_tmp.begin(), vec2_tmp.end());

        std::set_intersection(vec2_tmp.begin(), vec2_tmp.end(),
                            vec3.begin(), vec3.end(),
                            std::back_inserter(res));

        if (islower(res[0]))
            sum += (int)res[0] - 96;
        else
            sum += (int)res[0] - 38;

        cout << sum;



        vec1.clear();
        vec2.clear();
        vec3.clear();
        vec2_tmp.clear();
        res.clear();

    }
    return 0;
}
