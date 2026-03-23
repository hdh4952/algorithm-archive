#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

struct Beer {
    ll favor;
    ll ABV;
    Beer(ll v, ll c) : favor(v), ABV(c) {}
};

struct cmpPre {
    bool operator()(Beer a, Beer b) {
        return a.ABV > b.ABV;
    }
};

struct cmpNxt {
    bool operator()(Beer a, Beer b) {
        return a.favor > b.favor;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, M, K; cin >> N >> M >> K;
    ll v, c, nowValue = 0, answer;
    priority_queue<Beer, vector<Beer>, cmpPre> pre;
    priority_queue<Beer, vector<Beer>, cmpNxt> nxt;
    REP(i, 1, K) {
        cin >> v >> c;
        pre.emplace(v, c);
    }

    REP(i, 1, N) {
        nxt.push(pre.top());
        nowValue += pre.top().favor;
        answer = pre.top().ABV;
        pre.pop();
    }

    while(!pre.empty() && nowValue < M) {
        if(nxt.top().favor >= pre.top().favor) pre.pop();
        else {
            nowValue += pre.top().favor - nxt.top().favor;
            answer = pre.top().ABV;
            nxt.push(pre.top());
            pre.pop();
            nxt.pop();
        }
    }

    if(nowValue < M) cout << "-1";
    else cout << answer;
}