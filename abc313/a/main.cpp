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
    vector<int> P(N - 1);
    int a;
    cin >> a;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, N - 1) cin >> P[i];

    sort(all(P));
    reverse(all(P));

    cout << max(0LL, P[0] - a + 1) << endl;
}
