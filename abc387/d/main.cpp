#include "atcoder/all"
#include "bits/stdc++.h"
// #define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    int si, sj, gi, gj;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if (S[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    // vector<vector<int>> dist_odd(H, vector<int>(W, 1e9)), dist_even(H, vector<int>(W, 1e9));

    // priority_queue<pair<int, int>, greater<pair<int, int>>> pq;
}
