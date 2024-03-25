#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> T(M), A(M), X(M);
    rep(i, M) cin >> T[i] >> A[i] >> X[i];

    map<int, int> color;
    int decided_w_cnt_tmp = 0, decided_h_cnt_tmp = 0;
    set<int> decided_w, decided_h;
    for (int i = M - 1; i >= 0; i--) {
        if (T[i] == 1) {
            if (decided_h.count(A[i])) continue;
            color[X[i]] += W - decided_w_cnt_tmp;
            decided_h_cnt_tmp++;
            decided_h.insert(A[i]);
        } else {
            if (decided_w.count(A[i])) continue;
            color[X[i]] += H - decided_h_cnt_tmp;
            decided_w_cnt_tmp++;
            decided_w.insert(A[i]);
        }
    }

    int cnt = 0, sum = 0;
    for (auto [k, v] : color) {
        if (v > 0) cnt++;
        sum += v;
    }

    if (sum != H * W && color[0] == 0) cnt++;
    cout << cnt << endl;
    color[0] += H * W - sum;
    for (auto [k, v] : color) {
        if (v == 0) continue;
        cout << k << " " << v << endl;
    }
}
