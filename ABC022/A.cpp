#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S, T, W;
    cin >> N >> S >> T >> W;
    vector<int> A(N - 1);
    rep(i, N - 1) {
        cin >> A[i];
    }
    int cnt = 0;
    if (S <= W && W <= T) {
        cnt++;
    }
    rep(i, N - 1) {
        W += A[i];
        if (S <= W && W <= T) {
            cnt++;
        }
    }
    cout << cnt << endl;
}