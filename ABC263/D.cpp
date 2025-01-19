// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> Ls(N + 1), Rs(N + 1);
    int ml = 0, mr = 0;
    rep(i, N) {
        Ls[i + 1] = min(L * (i + 1), Ls[i] + A[i]);
        Rs[N - 1 - i] = min(R * (i + 1), Rs[N - i] + A[N - 1 - i]);
    }

    int ans = 1e18;
    rep(i, N + 1) {
        ans = min(ans, Ls[i] + Rs[i]);
    }
    cout << ans << endl;
}