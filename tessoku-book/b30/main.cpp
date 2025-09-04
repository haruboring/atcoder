#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int H, W;
    cin >> H >> W;
    H--, W--;

    // H+W C H
    vector<mint> A(H + W + 10);
    A[0] = 1, A[1] = 1;
    repp(i, 2, H + W + 1) A[i] = A[i - 1] * i;

    mint ans = A[H + W] / (A[H] * A[W]);
    cout << ans.val() << endl;
}
