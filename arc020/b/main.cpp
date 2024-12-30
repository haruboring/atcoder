#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 1e18;
    vector<int> colors = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int c1 : colors) {
        for (int c2 : colors) {
            if (c1 == c2) continue;
            int cost = 0;
            rep(i, N) {
                if (i % 2 == 0) {
                    if (A[i] != c1) cost += C;
                } else {
                    if (A[i] != c2) cost += C;
                }
            }
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
}
