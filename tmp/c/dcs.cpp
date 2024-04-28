// #include "atcoder/all"
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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, int> cnt;
    rep(i, N) cnt[A[i]]++;
    int all = N;

    int ans = 0;
    rep(i, (N + 1) / 2) {
        int a = cnt[A[i]];
        int b = cnt[A[N - 1 - i]];

        ans += (all - a) * (i + 1) + (all - b) * (i + 1);
        if (A[i] != A[N - 1 - i]) ans -= i + 1;
        all -= 2;
        cnt[A[i]]--;
        cnt[A[N - 1 - i]]--;
    }

    cout << ans << endl;
}