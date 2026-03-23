#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto v : commands) {
        vector<int> tmp;
        REP(i, v[0] - 1, v[1] - 1) 
            tmp.push_back(array[i]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[v[2] - 1]);
    }
    return answer;
}