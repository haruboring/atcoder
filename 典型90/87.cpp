#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, P, K;
    cin >> N >> P >> K;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    int l = 0, r = 1e18 + 100;
    while (r - l > 1) {
        int m = (l + r) / 2;

        vector<vector<int>> dist = A;
        rep(i, N) rep(j, N) if (dist[i][j] == -1) dist[i][j] = m;

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cnt = 0;
        rep(i, N - 1) {
            repp(j, i + 1, N) {
                if (dist[i][j] <= P) cnt++;
            }
        }

        if (cnt >= K) {
            l = m;
        } else {
            r = m;
        }
    }

    int R = r;

    l = 0, r = 1e18 + 100;
    while (r - l > 1) {
        int m = (l + r) / 2;

        vector<vector<int>> dist = A;
        rep(i, N) rep(j, N) if (dist[i][j] == -1) dist[i][j] = m;

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cnt = 0;
        rep(i, N - 1) {
            repp(j, i + 1, N) {
                if (dist[i][j] <= P) cnt++;
            }
        }

        if (cnt >= K + 1) {
            l = m;
        } else {
            r = m;
        }
    }

    int L = r;

    debug(L);
    debug(R);

    if (R - L > 1e9)
        cout << "Infinity" << endl;
    else
        cout << R - L << endl;
}
