#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    rep(i, N) {
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> bkp(N + 1, vector<ll>(W + 1));
    rep(i, N + 1) {
        rep(j, W + 1) {
            bkp[i][j] = -1;
        }
    }
    bkp[0][0] = 0;
    ll max_value = -1;
    repp(i, 1, N + 1) {
        rep(j, W + 1) {
            if (bkp[i - 1][j] != -1) {
                bkp[i][j] = max(bkp[i][j], bkp[i - 1][j]);
                if (j + w[i - 1] <= W) {
                    bkp[i][j + w[i - 1]] = max(bkp[i][j + w[i - 1]], bkp[i - 1][j] + v[i - 1]);
                }
            }
            max_value = max(max_value, bkp[i][j]);
        }
    }
    cout << max_value << endl;
}