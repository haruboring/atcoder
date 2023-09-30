#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    double ans = 0;

    repp(i, 1, N) {
        repp(j, 0, i) {
            int cnt = 0;
            repp(k, L[i], R[i] + 1) {
                repp(l, L[j], R[j] + 1) {
                    if (k < l) cnt++;
                }
            }

            ans += (double)cnt / ((R[i] - L[i] + 1) * (R[j] - L[j] + 1));
        }
    }

    cout << setprecision(10) << ans << endl;
}
