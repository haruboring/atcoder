#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<vector<int>> S(N, vector<int>(0));
    rep(i, N) {
        cin >> A[i];
        S[i].resize(A[i]);
        rep(j, A[i]) cin >> S[i][j];
    }

    map<int, int> dist;
    rep(i, 2e5 + 100) dist[i] = -1;

    map<int, vector<int>> has_is;
    rep(i, N) {
        for (int s : S[i]) {
            has_is[s].push_back(i);
        }
    }

    set<int> used;
    queue<pair<int, int>> q;
    for (auto i : has_is[1]) {
        for (int j : S[i]) {
            if (dist[j] == -1) {
                dist[j] = 0;
                if (j != M) q.push({j, 0});
            }
        }
        used.insert(i);
    }
    while (!q.empty()) {
        auto [i, d] = q.front();
        q.pop();
        for (int j : has_is[i]) {
            if (used.count(j)) continue;
            used.insert(j);
            for (int k : S[j]) {
                if (dist[k] == -1) {
                    dist[k] = d + 1;
                    q.push({k, d + 1});
                }
            }
        }
    }

    cout << dist[M] << endl;
}
