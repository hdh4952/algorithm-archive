#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[8];
vector<int> tmp, cnt;

void solve(int len) {
    if(len == n) {
        for(auto i : cnt) cout << i << " ";
        cout << "\n";
        return;
    }

    for(int i=0 ; i<tmp.size() ; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        cnt.push_back(tmp[i]);
        solve(len+1);
        cnt.pop_back();
        vis[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=1 ; i<=n ; i++) tmp.push_back(i);
    solve(0);
}