#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int fast_pow(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int lim = 40;
    double ans = 1e18;
    queue<tuple<int, double, int>> q;

    repp(i, 1, N) {
        double dist = sqrt((X[i] - X[0]) * (X[i] - X[0]) + (Y[i] - Y[0]) * (Y[i] - Y[0]));

        q.push({i, dist, 1});
    }

    while (!q.empty()) {
        auto [i, dist, cnt] = q.front();
        q.pop();

        if (N - cnt >= lim) continue;

        if (i == N - 1) {
            if (cnt == 0) {
                ans = min(ans, dist);
            } else {
                int sk = N - 1 - cnt;
                if (sk == 0) {
                    ans = min(ans, dist);
                } else {
                    ans = min(ans, dist + (double)fast_pow(2, sk - 1));
                }
            }
            continue;
        }

        repp(j, i + 1, N) {
            double new_dist = sqrt((X[j] - X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i]));
            q.push({j, dist + new_dist, cnt + 1});
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}