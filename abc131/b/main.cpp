#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> a(0);
    rep(i, N) a.push_back({abs(L + i + 1 - 1), L + i + 1 - 1});
    sort(all(a));

    int ans = 0;
    rep(i, N - 1) ans += a[i + 1].second;

    cout << ans << endl;
}
