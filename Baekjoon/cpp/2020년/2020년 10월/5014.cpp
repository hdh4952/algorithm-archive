#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int F, S, G, U, D, button = 0;
    bool vis[1000001] = {0, };
    queue<int> Q;

    cin >> F >> S >> G >> U >> D;
    Q.push(S);
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            int now = Q.front();
            Q.pop();
            if (now == G) {
                cout << button;
                return 0;
            }
            if (now + U <= F && vis[now+U] == false) {
                Q.push(now + U);
                vis[now+U] = true;
            }
            if (now - D > 0 && vis[now-D] == false) {
                Q.push(now - D);
                vis[now-D] = true;
            }
        }
        button++;
    }
    cout << "use the stairs";
}