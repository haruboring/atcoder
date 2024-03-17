#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, H, W;
    cin >> N >> H >> W;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<pair<int, int>> AB;
    rep(i, N) AB.push_back({A[i], B[i]});

    vector<int> orders(0);
    rep(i, N) {
        orders.push_back(i);
    }
    sort(all(orders));

    do {
        for (int i = 0; i < (1 << N); i++) {
            vector<vector<bool>> fill(H, vector<bool>(W, false));
            int idx = 0;

            bool ok = true;

            rep(s, H) {
                if (!ok) break;
                rep(t, W) {
                    if (fill[s][t]) continue;

                    if (idx >= N) {
                        ok = false;
                    }
                    if (!ok) break;

                    auto [h, w] = AB[orders[idx]];
                    if ((i >> idx) & 1) swap(h, w);

                    rep(ds, h) {
                        rep(dt, w) {
                            if (ds + s >= H || dt + t >= W) {
                                ok = false;
                                break;
                            }
                            if (fill[ds + s][dt + t]) {
                                ok = false;
                                break;
                            }
                            fill[ds + s][dt + t] = true;
                        }
                    }

                    idx++;
                    if (!ok) break;
                }
            }

            if (!ok) continue;

            int cnt = 0;
            rep(s, H) {
                rep(t, W) {
                    if (fill[s][t]) cnt++;
                }
            }

            if (cnt == H * W) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    } while (next_permutation(all(orders)));
    cout << "No" << endl;
}
