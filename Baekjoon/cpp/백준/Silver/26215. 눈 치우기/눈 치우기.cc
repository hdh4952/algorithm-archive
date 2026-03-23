#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int a = 0, b = 0, ans = 0, temp;
    priority_queue<int> snow;
    REP(i, 1, N) {
        cin >> temp ;
        snow.push(temp);
    }

    while(!snow.empty()) {
        a = snow.top();
        snow.pop();
        if(snow.empty()) {
            ans += a;
            break;
        } else {
            b = snow.top();
            snow.pop();
        }
        ans += b;
        if(a != b) snow.push(a - b);
    }

    if(ans > 1440) cout << "-1";
    else cout << ans;
}