#include <bits/stdc++.h>
using namespace std;

int n;
int a, b, c;
int UF[1000001];
int cnt[1000001];

int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x != y) cnt[x] += cnt[y];
    UF[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=1 ; i<=1000000 ; i++) {
        UF[i] = i;
        cnt[i] = 1;
    }
    while(n--) {
        char r;
        cin >> r;
        if(r == 'I') {
            cin >> a >> b;
            merge(a, b);
        }else if(r == 'Q') {
            cin >> c;
            cout << cnt[find(c)] << "\n";
        }
    }
}
