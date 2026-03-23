#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int, int>>> vvpii;

bool operator<(pair<int, int> &a, pair<int, int> &b) {
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

// {노드 개수, 비용}
pair<int, int> maxNodeAndCost(int N, int now, vvpii &graph, vvpii &cost, int pre) {
    pair<int, int> answer{0, 0};
    int idx = -1;
    for(auto [nxt, c] : graph[now]) {
        idx++;
        if(pre == nxt)
            continue;
        if(cost[now][idx].first == -1) {
            cost[now][idx] = maxNodeAndCost(N, nxt, graph, cost, now);
            ++cost[now][idx].first;
            cost[now][idx].second += c;
        }
        if(answer < cost[now][idx])
            answer = cost[now][idx];
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vvpii graph(N + 1), cost(N + 1);

    for(int i=0 ; i<N ; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].emplace_back(B, C);
        graph[B].emplace_back(A, C);
        cost[A].emplace_back(-1, -1);
        cost[B].emplace_back(-1, -1);
    }

    pair<int, int> answer{0, 0};
    for(int i=1 ; i<=N ; i++) {
        auto temp = maxNodeAndCost(N, i, graph, cost, 0);
        if(answer < temp)
            answer = temp;
    }

    cout << answer.second / T + bool(answer.second % T);
}