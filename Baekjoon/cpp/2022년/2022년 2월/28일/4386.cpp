#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int UF[101];
double ans;
vector<tuple<double, int, int>> edge;
double x[101];
double y[101];

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

    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        UF[i] = i;
        cin >> x[i] >> y[i];
        for(int j=1 ; j<i ; j++) {
            double cost = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
            edge.push_back({cost, i, j});
        }
    }

    sort(edge.begin(), edge.end());

    for(int i=0 ; edge.size() ; i++) {
        double cost;
        int a, b;
        tie(cost, a, b) = edge[i];
        if(find(a) == find(b)) continue;
        merge(a, b);
        ans += cost;
        cnt++;
        if(cnt == n-1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}