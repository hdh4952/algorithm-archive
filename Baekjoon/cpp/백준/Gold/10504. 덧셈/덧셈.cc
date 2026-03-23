#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

void solve() {
    ll N;
    cin >> N;
    REP(i, 2, 1e6) {
        if((2 * N - i * (i - 1)) <= 0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        if ((2 * N - i * (i - 1)) % (2 * i) == 0) {
            ll a = (2 * N - i * (i - 1)) / (2 * i);
            if (a > 0) {
                cout << N << " = ";
                REP(j, a, a + i - 2) cout << j << " + ";
                cout << a + i - 1 << "\n";
            } else cout << "IMPOSSIBLE\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();
}