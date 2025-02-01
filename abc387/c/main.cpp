#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L, R;
    cin >> L >> R;

    // r_cnt - l_cntで求めるのがまるそう
    int r_cnt = 0;
    string R_str = to_string(R);
    int N = R_str.size();

    int pre = 9;
    for (int i = 0; i < R_str.size() - 1; i++) {
        int cnt = min((int)(R_str[0] - '0'), (int)(R_str[i] - '0'));
        rep(_, R_str.size() - i - 1) cnt *= j;
        r_cnt += cnt;
    }
}
