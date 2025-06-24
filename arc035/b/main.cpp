#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int N;
    cin >> N;
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    sort(all(T));

    int ans = 0, t = 0;
    rep(i, N) {
        ans += t + T[i];
        t += T[i];
    }

    mint cnt = 1;
    map<int, int> m;
    rep(i, N) m[T[i]]++;
    for (auto [k, c] : m) repp(i, 1, c + 1) cnt *= i;

    cout << ans << endl;
    cout << cnt.val() << endl;
}
