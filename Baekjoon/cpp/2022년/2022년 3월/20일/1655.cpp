#include <bits/stdc++.h>
using namespace std;

int n, mid, nxt;
priority_queue<int, vector<int>, less<>> l;
priority_queue<int, vector<int>, greater<>> r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mid;
    cout << mid << "\n";

    for(int i=1 ; i<n ; i++) {
        cin >> nxt;
        if(mid > nxt) l.push(nxt);
        else r.push(nxt);

        if(l.size() == r.size() || l.size() + 1 == r.size()) cout << mid << "\n";
        else {
            if(l.size() < r.size()) {
                l.push(mid);
                mid = r.top();
                r.pop();
            }else {
                r.push(mid);
                mid = l.top();
                l.pop();
            }
            cout << mid << "\n";
        }
    }
}