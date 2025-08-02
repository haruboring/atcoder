#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    vector<int> t;
    rep(i, N) t.push_back(i);
    sort(all(t));

    map<pair<int, int>, int> m;
    rep(i, M) m[{A[i] - 1, B[i] - 1}] = C[i];
    int ans = 0;
    do {
        int d = 0;
        rep(idx, N - 1) {
            if (m[{min(t[idx], t[idx + 1]), max(t[idx], t[idx + 1])}] == 0) break;
            d += m[{min(t[idx], t[idx + 1]), max(t[idx], t[idx + 1])}];
            ans = max(ans, d);
        }
    } while (next_permutation(all(t)));

    cout << ans << endl;
}
