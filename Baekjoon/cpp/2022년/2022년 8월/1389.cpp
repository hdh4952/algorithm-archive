#include <bits/stdc++.h>
#define INF 10000
using namespace std;

int n, m, a, b, ans, maxLength = INF;
int cost[110][110];
int d[110][110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(i == j) continue;
             d[i][j] = cost[i][j] = INF;
        }
    }


    for(int i=0 ; i<m ; i++) {
        cin >> a >> b;
        d[a][b] = d[b][a] = cost[a][b] = cost[b][a] = 1;
    }

    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for(int i=1 ; i<=n ; i++) {
        int temp = 0;
        for(int j=1 ; j<=n ; j++) {
            if(i == j) continue;
            temp += d[i][j];
        }
        if(maxLength > temp) {
            ans = i;
            maxLength = temp;
        }
    }

    cout << ans;
}