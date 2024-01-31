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
    vector<int> d(N);
    rep(i, N) cin >> d[i];

    int longest = accumulate(all(d), 0LL);
    cout << longest << endl;

    vector<int> sum(N + 1, 0);
    rep(i, N) sum[i + 1] = sum[i] + d[i];

    if (N == 1) {
        cout << longest << endl;
        return 0;
    } else if (N == 2) {
        cout << abs(d[0] - d[1]) << endl;
    } else {
        int shortest = 1e9;
        rep(i, N - 2) {
            repp(j, i + 1, N - 1) {
                int a = sum[i + 1];
                int b = sum[j + 1] - sum[i + 1];
                int c = sum[N] - sum[j + 1];
                shortest = min(shortest, max(0LL, max({a, b, c}) - (a + b + c - max({a, b, c}))));
            }
        }
        cout << shortest << endl;
    }
}
