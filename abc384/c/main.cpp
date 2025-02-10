#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    vector<pair<int, string>> S(0);
    for (int i = 1; i < (1 << 5); i++) {
        int score = 0;
        bitset<5> bs(i);
        debug(bs);
        string s = "";
        if (bs[0]) {
            score += a;
            s += "A";
        }
        if (bs[1]) {
            score += b;
            s += "B";
        }
        if (bs[2]) {
            score += c;
            s += "C";
        }
        if (bs[3]) {
            score += d;
            s += "D";
        }
        if (bs[4]) {
            score += e;
            s += "E";
        }
        S.push_back({-score, s});
    }

    sort(all(S));
    rep(i, S.size()) cout << S[i].second << endl;
}
