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
    vector<int> p(N);
    rep(i, N) cin >> p[i];

    sort(all(p));
    int ans = 0;
    rep(i, N - 1) ans += p[i];
    ans += p[N - 1] / 2;

    cout << ans << endl;
}
