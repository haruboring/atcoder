#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 1);
    rep(i, M) cin >> A[i];
    A[M] = 1e9;

    rep(i, N) {
        int u = *upper_bound(all(A), i);
        cout << u - i - 1 << endl;
    }
}