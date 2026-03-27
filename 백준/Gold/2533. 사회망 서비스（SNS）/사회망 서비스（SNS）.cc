#include <bits/stdc++.h>
using namespace std;

int minCount(int here, int early, vector<vector<int>>& cache, vector<int>* children) {
    if (cache[here][early] != -1) return cache[here][early];
    
    int& ret = cache[here][early] = early;
    for (int child : children[here]) {
        if (early) ret += min(minCount(child, 0, cache, children), minCount(child, 1, cache, children));
        else ret += minCount(child, 1, cache, children);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    vector<int> adj[N+1];
    for (int i=0 ; i<N-1 ; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> children[N+1];
    vector<int> vis(N+1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int child : adj[now]) {
            if (vis[child]) continue;
            vis[child] = true;
            children[now].push_back(child);
            q.push(child);
        }
    }
    children[0].push_back(1);
    vector<vector<int>> cache(N+1, vector<int>(2, -1));
    cout << minCount(0, 1, cache, children) - 1;
}