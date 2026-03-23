#include <bits/stdc++.h>
using namespace std;

int n, s, res;
vector<int> v, tmp;
bool vis[20];

void f(int idx) {
    if(idx == n) {
        int sum = 0;
        if(!tmp.size()) return;
        for(auto i : tmp) sum += i;
        if(sum == s) res++;
    }else {
        tmp.push_back(v[idx]);
        f(idx+1);
        tmp.pop_back();
        f(idx+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> s;

    for(int i=0 ; i<n ; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    f(0);
    cout << res;
}