#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int N, M;

void dfs(int x, int y, vector<vector<char>> &v, vector<vector<bool>> &vis) {
    vis[x][y] = true;
    if (v[x][y] == '-' && y + 1 < M && v[x][y + 1] == '-') dfs(x, y + 1, v, vis);
    if (v[x][y] == '|' && x + 1 < N && v[x + 1][y] == '|') dfs(x + 1, y, v, vis);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M));
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    REP(i, 0, N - 1) {
        REP(j, 0, M - 1) {
            cin >> v[i][j];
        }
    }

    int answer = 0;
    REP(i, 0, N - 1) {
        REP(j, 0, M - 1) {
            if (vis[i][j]) continue;
            dfs(i, j, v, vis);
            answer++;
        }
    }
    cout << answer;
}