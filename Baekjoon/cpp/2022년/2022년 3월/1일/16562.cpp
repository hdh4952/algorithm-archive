#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt;
int UF[10001];
int A[10001];
bool vis[10001];

int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(A[x] < A[y]) UF[y] = x;
    else UF[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;

    for(int i=1 ; i<=n ; i++) {
        cin >> A[i];
        UF[i] = i;
    }
    while(m--) {
        int v, w;
        cin >> v >> w;
        merge(v ,w);
    }

    for(int i=1 ; i<=n ; i++) {
        int now = find(i);
        if(vis[now]) continue;
        vis[now] = true;
        cnt += A[now];
    }

    if(k >= cnt) cout << cnt;
    else cout << "Oh no";
}