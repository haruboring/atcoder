#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    rep(i, N) {
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> bkp(N + 1, vector<ll>(N * 1001));
    rep(i, N + 1) {
        rep(j, N * 1001) {
            bkp[i][j] = 10000000000;
        }
    }
    bkp[0][0] = 0;
    // [n_kome][sum_value] = sum_weight
    repp(i, 1, N + 1) {
        rep(j, N * 1001) {
            if (bkp[i - 1][j] != 10000000000) {
                bkp[i][j] = min(bkp[i][j], bkp[i - 1][j]);
                if (bkp[i-1][j] + w[i - 1] <= W) {
                    bkp[i][j + v[i - 1]] = min(bkp[i][j + v[i - 1]], bkp[i - 1][j] + w[i - 1]);
                }
            }
        }
    }
    ll max_value = -1;
    rep(i,N*1001){
        if(bkp[N][i]!=10000000000){
            max_value = i;
        }
    }
    cout << max_value << endl;
}