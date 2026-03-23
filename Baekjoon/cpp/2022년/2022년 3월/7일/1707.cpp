#include <bits/stdc++.h>
using namespace std;

void solve();
int v, e, a, b;
int vis[20001];
vector<int> adj[20001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int k;
    cin >> k;
    while(k--) solve();
}

void solve() {
    cin >> v >> e;

    for(int i=1 ; i<=v ; i++) {
        vis[i] = 0;
        adj[i].clear();
    }

    for(int i=0 ; i<e ; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    for(int i=1 ; i<=v ; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        q.push(i);
        while(!q.empty()) {
            int qsize = q.size();
            for(int j=0 ; j<qsize ; j++) {
                int now = q.front();
                q.pop();
                for(auto nxt : adj[now]) {
                    if(!vis[nxt]) {
                        if(vis[now] == 1) vis[nxt] = 2;
                        else vis[nxt] = 1;
                        q.push(nxt);
                    }else if(vis[nxt] == vis[now]) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "YES\n";
}