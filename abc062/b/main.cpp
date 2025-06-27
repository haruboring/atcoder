#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    vector<string> B(H + 2);
    string xx = "";
    rep(i, W + 2) xx += "#";
    B[0] = xx, B[H + 1] = xx;
    rep(i, H) B[i + 1] = "#" + A[i] + "#";

    rep(i, H + 2) cout << B[i] << endl;
}
