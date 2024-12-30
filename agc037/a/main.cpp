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

    vector<vector<int>> cnt(2, vector<int>(S.size()));
    cnt[0][0] = 1, cnt[1][0] = 0;
    repp(i, 1, S.size()) {
        cnt[0][i] = max(cnt[0][i], cnt[1][i - 1] + 1);
        if (S[i - 1] != S[i]) cnt[0][i] = max(cnt[0][i], cnt[0][i - 1] + 1);
        if (i > 2) {
            if (S.substr(i - 3, 2) != S.substr(i - 1, 2)) {
                cnt[1][i] = max(cnt[1][i], cnt[0][i - 2] + 1);
            }
        }
        if (i > 1) {
            cnt[1][i] = max(cnt[1][i], cnt[0][i - 2] + 1);
        }
    }

    cout << max(cnt[0][S.size() - 1], cnt[1][S.size() - 1]) << endl;
}
