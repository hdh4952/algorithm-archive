#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int arr[3001][3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> v(N), deg(N+1, 0);
    vector<int> adj[N + 1];
    REP(t, 1, 3) {
        REP(x, 0, N-1) cin >> v[x];
        REP(i, 0, N-2) {
            REP(j, i+1, N-1) {
                arr[v[i]][v[j]]++;
                if(arr[v[i]][v[j]] == 2) {
                    adj[v[i]].push_back(v[j]);
                    deg[v[j]]++;
                }
            }
        }
    }

    queue<int> q;
    REP(i, 1, N) if(deg[i] == 0) q.push(i);
    while(!q.empty()) {
        size_t qsize = q.size();
        REP(i, 1, qsize) {
            int now = q.front();
            q.pop();
            cout << now << " ";
            for(auto nxt : adj[now]) {
                deg[nxt]--;
                if(deg[nxt] == 0) q.push(nxt);
            }
        }
    }
}