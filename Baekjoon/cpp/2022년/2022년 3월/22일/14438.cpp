#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000001
using namespace std;

int n, m;
ll tree[400000];
vector<ll> arr;

ll init(int node, int s, int e) {
    if(s == e) return tree[node] = arr[s];
    int mid = (s+e)/2;
    return tree[node] = min(init(node*2, s, mid), init(node*2+1, mid+1, e));
}

ll le(int node, int s, int e, int l, int r) {
    if(l > e || r < s) return INF;
    if(l <= s && e <= r) return tree[node];
    int mid = (s+e)/2;
    return min(le(node*2, s, mid, l, r), le(node*2+1, mid+1, e, l, r));
}

ll update(int node, int s, int e, int idx, ll value) {
    if(!(s <= idx && idx <= e)) return tree[node];
    if(s != e) {
        int mid = (s+e)/2;
        return tree[node] = min(update(node*2, s, mid, idx, value), update(node*2+1, mid+1, e, idx, value));
    }else return tree[node] = value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    init(1, 0, n-1);
    cin >> m;
    while(m--) {
        int order;
        cin >> order;
        if(order == 1) {
            int i;
            ll v;
            cin >> i >> v;
            update(1, 0, n-1, i-1, v);
        }else if(order == 2) {
            int i, j;
            cin >> i >> j;
            cout << le(1, 0, n-1, i-1, j-1) << "\n";
        }
    }
}