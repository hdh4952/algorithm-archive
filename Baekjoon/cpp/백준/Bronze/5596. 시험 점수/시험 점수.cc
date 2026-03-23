#include <bits/stdc++.h>

#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    vector<int> v(2, 0);
    for (auto &i: v) {
        int x;
        REP(a, 1, 4) {
            cin >> x;
            i += x;
        }
    }

    cout << *max_element(v.begin(), v.end());
}