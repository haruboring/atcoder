#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> P(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> P[i][j];
    vector<vector<int>> R(N, vector<int>(N - 1));
    rep(i, N) rep(j, N - 1) cin >> R[i][j];
    vector<vector<int>> D(N - 1, vector<int>(N));
    rep(i, N - 1) rep(j, N) cin >> D[i][j];

    vector<vector<int>> G(N * N, vector<int>(0));
    rep(i, N) {
        rep(j, N) {
            if (i != N - 1) {
                G[(i + 1) * N + j].push_back((i)*N + j);
            }
            if (j != N - 1) {
                G[i * N + j + 1].push_back(i * N + j);
            }
        }
    }

    vector<int> dist(N * N, 1e9);
    dist[N * N - 1] = 0;
}
