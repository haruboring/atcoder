#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    cout << (5) % (-5) << endl;
    int N, K;
    cin >> N >> K;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    vector<int> DX(0), DY(0);
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            DX.push_back(X[j] - X[i]);
            DY.push_back(Y[j] - Y[i]);
        }
    }

    set<pair<int, int>> st;
    rep(i, DX.size()) {
        if (DX[i] * DY[i] >= 0) {
            DX[i] = abs(DX[i]);
            DY[i] = abs(DY[i]);
        } else {
            if (DX[i] >= 0) continue;
            DX[i] *= -1;
            DY[i] *= -1;
        }
        int mag = gcd(DX[i], DY[i]);
        st.insert({DX[i] / mag, DY[i] / mag});
    }

    int ans = 0;

    for (auto [dx, dy] : st) {
        cout << "dx: " << dx << ", dy: " << dy << endl;
        vector<bool> unused(N, false);
        rep(i, N) {
            if (unused[i]) continue;
            int cnt = 0;
            repp(j, i + 1, N) {
                if (unused[j]) continue;
                int ddx = X[j] - X[i];
                int ddy = Y[j] - Y[i];

                bool ok = true;
                if (dx * dx == 0) {
                    if (dx != 0 && ddy % dy != 0) ok = false;
                    if (dy != 0 && ddx % dx != 0) ok = false;
                } else {
                }

                if (ok) {
                    unused[j] = true;
                    unused[j] = true;
                    cnt++;
                }
            }
            if (cnt >= K) ans++;
        }
    }

    cout << ans << endl;
}
