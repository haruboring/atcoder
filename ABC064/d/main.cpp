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

    int cnt = 0;
    string ans = "";
    rep(i, N) {
        if (S[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }
        ans += S[i];

        if (cnt < 0) {
            ans = "(" + ans;
            cnt = 0;
        }
    }
    rep(i, cnt) ans += ")";

    cout << ans << endl;
}
