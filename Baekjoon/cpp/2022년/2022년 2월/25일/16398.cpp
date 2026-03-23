#include <bits/stdc++.h>
using namespace std;

int n, cnt;
long long int ans;
int UF[1001];
vector<tuple<int, int, int>> v;

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

    for(int i=1 ; i<=n ; i++) UF[i] = i;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            int cost;
            cin >> cost;
            if(i<j) v.push_back({cost, i, j});
        }
    }

    sort(v.begin(), v.end());
    for(int i=0 ; i<v.size() ; i++) {
        int a, b, cost;
        tie(cost, a, b) = v[i];
        if(find(a) == find(b)) continue;
        merge(a, b);
        ans += cost;
        cnt++;
        if(cnt == n-1) break;
    }

    cout << ans;
}