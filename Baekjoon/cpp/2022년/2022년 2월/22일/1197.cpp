#include <bits/stdc++.h>
using namespace std;

int v, e, ans, cnt;
int UF[10001];
tuple<int, int, int> edge[100001];

int find(int a) {
    return UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    UF[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> v >> e;
    for(int i=1 ; i<=v ; i++) UF[i] = i;
    for(int i=0 ; i<e ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge, edge+e);

    for(int i=0 ; i<e ; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(find(a) == find(b)) continue;
        ans += cost;
        merge(a, b);
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
}