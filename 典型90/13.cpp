#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    vector<vector<pair<int, int>>> G(N);
    rep(i, M) {
        A[i]--;
        B[i]--;
        G[A[i]].push_back({B[i], C[i]});
        G[B[i]].push_back({A[i], C[i]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> dist_from_0(N, 1e9);
    dist_from_0[0] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist_from_0[v] < d) continue;
        for (auto [i, w] : G[v]) {
            if (dist_from_0[i] > dist_from_0[v] + w) {
                dist_from_0[i] = dist_from_0[v] + w;
                pq.push({dist_from_0[i], i});
            }
        }
    }

    pq.push({0, N - 1});
    vector<int> dist_from_N_1(N, 1e9);
    dist_from_N_1[N - 1] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist_from_N_1[v] < d) continue;
        for (auto [i, w] : G[v]) {
            if (dist_from_N_1[i] > dist_from_N_1[v] + w) {
                dist_from_N_1[i] = dist_from_N_1[v] + w;
                pq.push({dist_from_N_1[i], i});
            }
        }
    }

    rep(i, N) {
        cout << dist_from_0[i] + dist_from_N_1[i] << endl;
    }
}