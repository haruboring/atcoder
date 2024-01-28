#include "atcoder/all"
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
    int Ncopy = N;
    vector<int> ans(0);
    ans.push_back(0);
    int bit_cnt = 1;
    while (1) {
        if (bit_cnt > Ncopy) {
            break;
        }
        if (N % 2 == 1) {
            int size = ans.size();
            rep(i, size) {
                ans.push_back(ans[i] + bit_cnt);
            }
        }
        N /= 2;
        bit_cnt *= 2;
    }
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
}