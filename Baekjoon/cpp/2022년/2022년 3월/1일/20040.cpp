#include <bits/stdc++.h>
using namespace std;

int n, m, t, cnt, ans;
int UF[500001];

int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    UF[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0 ; i<n ; i++) UF[i] = i;

    while(m--) {
        t++;
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b) && !ans) ans = t;
        merge(a, b);
    }

    cout << ans;
}
