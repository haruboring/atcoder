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

    int l_cnt = 0;
    rep(i, S.size()) {
        if (islower(S[i])) l_cnt++;
    }

    string ans = S;
    if (l_cnt > S.size() - l_cnt) {
        rep(i, S.size()) {
            if (isupper(S[i])) S[i] = tolower(S[i]);
        }
    } else {
        rep(i, S.size()) {
            if (islower(S[i])) S[i] = toupper(S[i]);
        }
    }

    cout << S << endl;
}
