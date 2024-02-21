#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    vector<int> cnt(100000 + 100, 0);
    repp(i, 2, 100000 + 10) {
        if (i % 2 == 0) {
            cnt[i] = cnt[i - 1];
            continue;
        }
        bool is_prime = true;
        repp(j, 2, sqrt(i) + 1) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        repp(j, 2, sqrt((i + 1) / 2) + 1) {
            if (((i + 1) / 2) % j == 0) {
                is_prime = false;
                break;
            }
        }

        cnt[i] += cnt[i - 1];
        if (is_prime && i % 2 == 1) {
            cnt[i] += 1;
        }
    }

    rep(i, Q) {
        cout << cnt[R[i]] - cnt[L[i] - 1] << endl;
    }
}
