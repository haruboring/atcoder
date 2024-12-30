#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    sort(all(a));

    int cnt = 0;
    rep(i, N - 1) {
        if (x - a[i] >= 0) {
            cnt++;
        }
        x -= a[i];
    }
    if (a[N - 1] == x) cnt++;

    cout << cnt << endl;
}
