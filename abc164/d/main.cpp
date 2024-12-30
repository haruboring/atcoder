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

    vector<int> cnt(2019, 0);
    cnt[0] = 1;
    int num = 0;
    int ten = 1;
    rep(i, S.size()) {
        num = (num + (S[S.size() - 1 - i] - '0') * ten) % 2019;
        ten = ten * 10 % 2019;
        cnt[num]++;
    }

    int ans = 0;
    rep(i, 2019) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans << endl;
}
