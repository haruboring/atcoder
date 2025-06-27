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

    S = "Z" + S + "Z";

    int cnt = 1;
    map<char, int> m;
    rep(i, N + 1) {
        if (S[i] != S[i + 1]) {
            m[S[i]] = max(m[S[i]], cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }

    int ans = 0;
    for (auto [c, cnt] : m) {
        if (c == 'Z') continue;
        ans += cnt;
    }

    cout << ans << endl;
}
