// #include "atcoder/all"
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
    vector<int> A(N), F(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> F[i];
    }

    sort(all(F));
    sort(all(A));
    reverse(all(A));

    int l = -1, r = 1e18;
    while (r - l > 1) {
        int m = (l + r) / 2;

        vector<int> maxA(N);
        rep(i, N) {
            maxA[i] = m / F[i];
        }
        int cnt = 0;
        rep(i, N) {
            cnt += max(0LL, A[i] - maxA[i]);
        }
        if (cnt <= K) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
}