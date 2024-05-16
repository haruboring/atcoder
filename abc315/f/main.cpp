#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int fast_pow(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

signed main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<vector<double>> dist(N, vector<double>(40, 1e18));
    dist[0][0] = 0;
    rep(i, N) {
        rep(j, 40) {
            if (dist[i][j] == 1e18) continue;
            repp(k, i + 1, N) {
                if (j + k - (i + 1) >= 40) continue;
                double d = sqrt((X[i] - X[k]) * (X[i] - X[k]) + (Y[i] - Y[k]) * (Y[i] - Y[k]));
                dist[k][j + k - (i + 1)] = min(dist[k][j + k - (i + 1)], dist[i][j] + d);
            }
        }
    }

    double ans = dist[N - 1][0];
    repp(i, 1, 40) ans = min(ans, dist[N - 1][i] + fast_pow(2, i - 1));

    cout << fixed << setprecision(10) << ans << endl;
}
