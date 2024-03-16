#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;

    double ans = 0;
    repp(i, 1, N + 1) {
        double p = 1;
        int s = i;
        while (s < K) {
            s *= 2;
            p /= 2;
        }

        ans += p / N;
    }

    cout << fixed << setprecision(10) << ans << endl;
}
