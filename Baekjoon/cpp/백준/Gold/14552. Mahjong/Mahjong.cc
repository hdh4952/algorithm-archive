#include <bits/stdc++.h>
using namespace std;

void makeBody(vector<int> &cnt, bool &isComplete, int step) {
    if (step == 4) {
        isComplete = true;
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (cnt[i] >= 3) {
            cnt[i] -= 3;
            makeBody(cnt, isComplete, step + 1);
            if (isComplete) return;
            cnt[i] += 3;
        }
        if (i < 8 && cnt[i] && cnt[i + 1] && cnt[i + 2]) {
            --cnt[i];
            --cnt[i + 1];
            --cnt[i + 2];
            makeBody(cnt, isComplete, step + 1);
            if (isComplete) return;
            ++cnt[i];
            ++cnt[i + 1];
            ++cnt[i + 2];
        }
    }
}

bool oneHeadFourBody(vector<int> &cnt) {
    bool isComplete = false;
    for (int i = 1; i < 10; i++) {
        if (cnt[i] >= 2) {
            cnt[i] -= 2;
            makeBody(cnt, isComplete, 0);
            cnt[i] += 2;
        }
    }
    return isComplete;
}

bool isAvailable(vector<int> &v) {
    return all_of(v.begin(), v.end(), [](int i) { return i <= 4; });
}

bool check(vector<int> &v) {
    vector<int> cnt(10, 0);
    for (auto i: v)
        ++cnt[i];

    if (!isAvailable(cnt)) return false;
    if (7 == count_if(cnt.begin() + 1, cnt.end(), [](int i) {
        return i == 2;
    }))
        return true;
    if (oneHeadFourBody(cnt)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(13), answer;
    for (auto &i: v)
        cin >> i;

    for (int i = 1; i < 10; i++) {
        v.push_back(i);
        if (check(v))
            answer.push_back(i);
        v.pop_back();
    }

    if (answer.empty())
        cout << "-1";
    else {
        for (auto i: answer)
            cout << i << " ";
    }
}