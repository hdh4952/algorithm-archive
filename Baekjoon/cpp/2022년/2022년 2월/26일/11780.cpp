#include <bits/stdc++.h> //https://blog.encrypted.gg/1035?category=773649
#define INF 100000000
using namespace std;

int n, m;
int arr[101][101];
int nxt[101][101];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            arr[i][j] = INF;

    for(int i=0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
        nxt[a][b] = b;
    }
    for(int i=1 ; i<=n ; i++) arr[i][i] = 0;

    for(int k=1 ; k<=n ; k++) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(arr[i][j] > arr[i][k]+arr[k][j]) {
                    arr[i][j] = arr[i][k]+arr[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }


    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(arr[i][j] == INF) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(arr[i][j] == 0 || arr[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int s = i;
            while(s != j) {
                path.push_back(s);
                s = nxt[s][j];
            }
            path.push_back(j);
            cout << path.size() << " ";
            for(auto x : path) cout << x << " ";
            cout << "\n";
        }
    }
}