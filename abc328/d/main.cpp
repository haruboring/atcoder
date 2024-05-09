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

    string ans = "";
    int N = S.size();
    rep(i, N) {
        ans += S[i];
        while (1) {
            if (ans.size() > 2 && ans[ans.size() - 3] == 'A' && ans[ans.size() - 2] == 'B' && ans[ans.size() - 1] == 'C') {
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            } else
                break;
        }
    }

    cout << ans << endl;
}