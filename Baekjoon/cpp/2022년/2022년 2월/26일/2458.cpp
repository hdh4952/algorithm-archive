#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int n, m, ans;
int tall[501][501];
int lit[501][501];
int check[501];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            tall[i][j] = lit[i][j] = INF;

    for(int i=1 ; i<=n ; i++) tall[i][i] = lit[i][i] = 0;

    while(m--) {
        int a, b;
        cin >> a >> b;
        tall[a][b] = 1; // a키 < b키
        lit[b][a] = 1;
    }

    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                tall[i][j] = min(tall[i][j], tall[i][k]+tall[k][j]);
                lit[i][j] = min(lit[i][j], lit[i][k]+lit[k][j]);
            }
        }
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(i == j || tall[i][j] == INF && lit[i][j] == INF) continue;
            check[i]++;
        }
        if(check[i] == n-1) ans++;
    }

    cout << ans;
}