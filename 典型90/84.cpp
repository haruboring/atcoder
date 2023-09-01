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
    string S;
    cin >> S;

    vector<int> sum_o(N + 1), sum_x(N + 1);
    rep(i, N) {
        sum_o.at(i + 1) = sum_o.at(i);
        sum_x.at(i + 1) = sum_x.at(i);
        if (S.at(i) == 'o') {
            sum_o.at(i + 1)++;
        } else {
            sum_x.at(i + 1)++;
        }
    }

    int ans = 0;

    rep(i, N) {
        int o = sum_o.at(i);
        int x = sum_x.at(i);
        int itr_o = lower_bound(all(sum_o), o + 1) - sum_o.begin();
        int itr_x = lower_bound(all(sum_x), x + 1) - sum_x.begin();

        ans += N - max(itr_o, itr_x) + 1;
    }

    cout << ans << endl;
}
