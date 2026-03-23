#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, N; cin >> A >> B >> N;
    vector<map<int, bool>> v(N + 1);
    v[1][A+B] = true;
    REP(i, 2, N) {
        for(auto [height, isExist] : v[i - 1]) {
            v[i][height + A] = true;
            v[i][height + A + B] = true;
        }
    }

    for(auto [height, isExist] : v[N]) cout << height << " ";
}