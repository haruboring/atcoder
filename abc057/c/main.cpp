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

    int ans = 1e18;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            string a = to_string(i);
            string b = to_string(N / i);
            ans = min(ans, (int)max(a.size(), b.size()));
        }
    }

    cout << ans << endl;
}
