#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(8, vector<int>());

vector<int> cal(int N, int cnt) {
    if (!memo[cnt-1].empty()) return memo[cnt-1];
    
    set<int> s;
    int concat = N;
    for (int i=0 ; i<cnt-1 ; i++) {
        concat *= 10;
        concat += N;
    }
    s.insert(concat);
    for (int i=1 ; i<=cnt/2 ; i++) {
        auto a = cal(N, i);
        auto b = cal(N, cnt-i);
        for (auto x : a) {
            for (auto y : b) { 
                s.insert(x+y);
                s.insert(x-y);
                s.insert(x*y);
                if (y != 0) s.insert(x/y);
                if (x != 0) s.insert(y/x);
            }
        }
    }
    
    for (const auto& i : s) {
        memo[cnt-1].push_back(i);
    }
    return memo[cnt-1];
}

int solution(int N, int number) {
    memo[0] = {N};
    memo[1] = {1, N+N, N-N, N*N, N*10+N};
    for (int i=1 ; i<9 ; i++) {
        for (auto x : cal(N, i)) {
            if (x == number) return i;
        }
    }
    
    return -1;
}