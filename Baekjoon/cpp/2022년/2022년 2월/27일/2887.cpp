#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, cnt;
ll ans;
int UF[100001];
vector<tuple<ll, int, int>> edge;
vector<pair<ll, int>> xp, yp, zp;

int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    UF[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=1 ; i<=n ; i++) {
        UF[i] = i;
        ll x, y, z;
        cin >> x >> y >> z;
        xp.push_back({x, i});
        yp.push_back({y, i});
        zp.push_back({z, i});
    }

    sort(xp.begin(), xp.end());
    sort(yp.begin(), yp.end());
    sort(zp.begin(), zp.end());
    for(int i=0 ; i<n-1 ; i++) edge.push_back({xp[i+1].first-xp[i].first, xp[i].second, xp[i+1].second});
    for(int i=0 ; i<n-1 ; i++) edge.push_back({yp[i+1].first-yp[i].first, yp[i].second, yp[i+1].second});
    for(int i=0 ; i<n-1 ; i++) edge.push_back({zp[i+1].first-zp[i].first, zp[i].second, zp[i+1].second});

    sort(edge.begin(), edge.end());

    for(int i=0 ; i<n*3; i++) {
        ll c;
        int a, b;
        tie(c, a, b) = edge[i];
        if(find(a) == find(b)) continue;
        merge(a, b);
        cnt++;
        ans += c;
        if(cnt == n-1) break;
    }

    cout << ans;
}