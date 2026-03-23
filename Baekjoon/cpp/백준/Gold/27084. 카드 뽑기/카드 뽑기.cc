#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> cnt(N + 1, 0);
    int An;
    REP(i, 1, N) {
        cin >> An;
        cnt[An]++;
    }

    ll ans = 1;
    REP(i, 1, N) {
        if(cnt[i]) {
            ans *= cnt[i] + 1;
            ans %= 1000000007;
        }
    }

    cout << ans - 1;
}