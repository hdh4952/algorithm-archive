#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i=2 ; i*i<=n ; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void check(int n, priority_queue<int> &my, priority_queue<int> &other, ll &myScore, ll &otherScore, map<int, bool> &isExist) {
    if(!isPrime(n)) {
        if(other.size() < 3)
            otherScore += 1000;
        else {
            vector<int> v;
            for(int i=0 ; i<3 ; i++) {
                v.push_back(other.top());
                other.pop();
            }
            otherScore += v.back();
            for(auto i : v)
                other.push(i);
        }
    } else if(isExist.find(n) != isExist.end()) {
        myScore -= 1000;
    } else {
        my.push(n);
        isExist[n] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, dwScore = 0, gsScore = 0;
    cin >> N;
    priority_queue<int> dw, gs;
    map<int, bool> isExist;

    while(N--) {
        int a, b;
        cin >> a >> b;
        check(a, dw, gs, dwScore, gsScore, isExist);
        check(b, gs, dw, gsScore, dwScore, isExist);
    }

    if(dwScore != gsScore)
        cout << (dwScore > gsScore ? "소수의 신 갓대웅" : "소수 마스터 갓규성");
    else
        cout << "우열을 가릴 수 없음";
}