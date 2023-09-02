#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);
    rep(i, N) cin >> F[i];

    sort(all(F));
    reverse(all(F));
    int ans = 0;

    int j = 0;
    while (1) {
        int tmp = 0;
        repp(i, j, j + min(N - j, D)) {
            tmp += F[i];
        }
        if (tmp > P)
            ans += P;
        else
            ans += tmp;
        j += min(N, D);
        if (j >= N) break;
    }
    cout << ans << endl;
}