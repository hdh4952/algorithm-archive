#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int cmp(const string& a, const string& b) {
  int ans = 0;
  REP(i, 0, a.size() - 1) if(a[i] != b[i]) ans++;
  return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B; cin >> A >> B;
    int ans = 1e9;
    REP(i, 0, B.size() - A.size()) ans = min(ans, cmp(A, B.substr(i, i + A.size())));
    cout << ans;
}