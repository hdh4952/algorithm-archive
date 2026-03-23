#include <bits/stdc++.h>
using namespace std;

void f();
void solve(int cnt);
bool vis[12];
int s[12][12];
int ans;
int cmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) f();
}

void f() {
    ans = 0;
    for(int i=1 ; i<=11 ; i++)
        for(int j=1 ; j<=11 ; j++)
            cin >> s[i][j];

    solve(0);
    cout << ans << "\n";
}

void solve(int cnt) {
    if(cnt == 11) {
        ans = max(ans, cmp);
        return;
    }

    for(int i=1 ; i<=11 ; i++) {
        if(vis[i] || !s[i][cnt+1]) continue;
        vis[i] = true;
        cmp += s[i][cnt+1];
        solve(cnt+1);
        cmp -= s[i][cnt+1];
        vis[i] = false;
    }
}