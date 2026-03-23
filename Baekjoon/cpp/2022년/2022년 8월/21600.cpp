#include <bits/stdc++.h>
using namespace std;

long long int answer, cnt, now;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> now;
        if(cnt + 1 <= now) {
            cnt += 1;
            if(answer < cnt) answer = cnt;
        } else cnt = now;
    }

    cout << answer;
}