#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
っg
signed main() {
    string S;
    cin >> S;

    int MOD = 1000000007;

    string chok = "chokudai";
    vector<vector<int>> a(chok.size(), vector<int>(S.size()));
    int cnt = 0;
    rep(i, S.size()) {
        if (S[i] == 'c') cnt++;
        a[0][i] = cnt;
    }
    repp(i, 1, chok.size()) {
        char c = chok[i];
        repp(j, 1, S.size()) {
            a[i][j] += a[i][j - 1];
            if (S[j] == c) a[i][j] += a[i - 1][j - 1];
            a[i][j] %= MOD;
        }
    }

    cout << a[chok.size() - 1][S.size() - 1] % MOD << endl;
}
