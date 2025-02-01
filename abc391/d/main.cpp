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
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    int Q;
    cin >> Q;
    vector<int> T(Q), A(Q);
    rep(i, Q) cin >> T[i] >> A[i];

    rep(i, N) X[i]--;
    vector<set<int>> S(W);
    rep(i, N) S[X[i]].insert(Y[i]);

    map<int, int> t;
    while (1) {
        bool b = false;
        rep(c, 1e9) {
            int tmp = -1;
            int cnt = 0;
            for (int i = 0; i < W; i++) {
                if (S[i].size() == 0) break;
                cnt++;

                int y = *S[i].begin();
                S[i].erase(y);

                tmp = max(tmp, y);
            }

            if (cnt != W) {
                b = true;
                break;
            }
            t[c] = tmp;
        }
        if (b) break;
    }

    int max_c = 0;
    for (auto [k, v] : t) max_c = max(max_c, k + 1);

    map<int, int> die_time;
    rep(i, N) die_time[i] = 1e18;

    vector<set<pair<int, int>>> Si(W);
    rep(i, N) Si[X[i]].insert({Y[i], i});
    debug(max_c);
    rep(i, W) {
        rep(j, max_c) {
            auto [y, idx] = *Si[i].begin();
            Si[i].erase({y, idx});
            die_time[idx] = t[j];
            // debug(idx);
        }
    }

    // rep(i, N) {
    //     cout << die_time[i] << endl;
    // }

    debug("owa");

    rep(i, Q) {
        if (die_time[A[i] - 1] > T[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
