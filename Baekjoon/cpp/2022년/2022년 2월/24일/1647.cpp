#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans;
int UF[100001];
tuple<int, int, int> edge[1000001];

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

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) UF[i] = i;
    for(int i=0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge, edge+m);

    for(int i=0 ; i<m ; i++) {
        int a, b, c;
        tie(c, a, b) = edge[i];
        if(find(a) == find(b)) continue;
        merge(a, b);
        cnt++;
        ans += c;
        if(cnt == n-2) break;
    }

    cout << ans;
}