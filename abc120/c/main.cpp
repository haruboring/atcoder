#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int N = S.size();

    int zero_cnt = 0, one_cnt = 0;
    rep(i, N) {
        if (S[i] == '0') {
            zero_cnt++;
        } else {
            one_cnt++;
        }
    }

    cout << 2 * min(zero_cnt, one_cnt) << endl;
}
