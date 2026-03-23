#include <bits/stdc++.h>
using namespace std;

vector<int> init(int n) {
    vector<int> ans;
    for(int i=1 ; i*i<=n ; i++)
        ans.push_back(i*i);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> squares = init(n);
    vector<int> table(n+1, 4);
    for(auto &square : squares)
        table[square] = 1;
    for(int i=2 ; i<=n ; i++) {
        if(table[i] != 4) continue;
        for(auto &square : squares) {
            if(square > i) break;
            table[i] = min(table[i], table[square] + table[i - square]);
        }
    }
    cout << table[n];
}