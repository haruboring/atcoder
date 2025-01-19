#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];

    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                if (i < j && j < k && L[i] != L[j] && L[j] != L[k] && L[i] != L[k]) {
                    if (L[i] < L[j] + L[k] && L[j] < L[i] + L[k] && L[k] < L[i] + L[j]) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
