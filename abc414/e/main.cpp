#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

mint aa(int n) {  // https://atcoder.jp/contests/abc230/submissions/27644486
    mint ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);               // 计算r，让分块右移
        ans += (r - l + 1) * (n / l);  // 求和
    }
    return ans;
}

signed main() {
    int N_;
    cin >> N_;

    mint N = N_;

    mint ans = (N + 1) * N / 2 - aa(N_);

    cout << ans.val() << endl;
}
