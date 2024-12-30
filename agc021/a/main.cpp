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

    string S = to_string(N);
    reverse(all(S));

    int ans = 0;

    // 8未満の時桁落とした方がいいという話？
    bool drop_keta = false;
    vector<int> tmp;
    rep(i, S.size()) {
        int a = S[i] - '0';
        if (drop_keta) a--;
        if (a < 9 && i < S.size() - 1) {
            a = 9;
            drop_keta = true;
        } else {
            drop_keta = false;
        }

        ans += a;
        tmp.push_back(a);
    }
    reverse(all(tmp));
    // rep(i, tmp.size()) cout << tmp[i];
    // cout << endl;
    cout << ans << endl;
}
