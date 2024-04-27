#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> A(9);
    vector<int> B(8);
    rep(i, 9) cin >> A[i];
    rep(i, 8) cin >> B[i];

    int t = accumulate(all(A), 0LL);
    int a = accumulate(all(B), 0LL);
    cout << t - a + 1 << endl;
}
