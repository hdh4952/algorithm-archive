#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N), ans(N, 0);
    for (auto &i: v) cin >> i;
    REP(i, 0, N - 1) ans[i] = i + 1;
    REP(i, 0, N - 1) {
        for (int j = i - 1; j >= i - v[i]; j--) ans[j + 1] = ans[j];
        ans[i - v[i]] = i + 1;
    }
    for (auto i: ans) cout << i << " ";
}