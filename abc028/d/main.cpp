#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    double N, K;
    cin >> N >> K;

    double ans = 6 * ((K - 1) / N) * (1 / N) * ((N - K) / N);  // xoz
    ans += 3 * (1 / N) * (1 / N) * ((N - K) / N);              // ooz
    ans += 3 * ((K - 1) / N) * (1 / N) * (1 / N);              // xoo
    ans += (1 / N) * (1 / N) * (1 / N);                        // ooo

    cout << fixed << setprecision(20) << ans << endl;
}
