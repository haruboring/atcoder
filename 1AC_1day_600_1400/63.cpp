#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int_least32_t main() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D), R(D);
    rep(i, D) cin >> L[i] >> R[i];
    vector<int> S(K), T(K);
    rep(i, K) cin >> S[i] >> T[i];

    rep(i, K) {
        int ans = 0;
        int now = S[i];
        if (S[i] < T[i]) {
            rep(j, D) {
                if (L[j] <= now && now <= R[j]) {
                    now = R[j];
                    ans = j + 1;
                }
                if (now >= T[i]) {
                    cout << ans << endl;
                    break;
                }
            }
        } else {
            rep(j, D) {
                if (L[j] <= now && now <= R[j]) {
                    now = L[j];
                    ans = j + 1;
                }
                if (now <= T[i]) {
                    cout << ans << endl;
                    break;
                }
            }
        }
    }
}
