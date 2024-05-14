#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int ans = 0;
    map<pair<int, char>, set<int>> cnt;
    rep(i, N) {
        cnt[{0, S[i][0]}].insert(i);
    }
    for (auto [_, cc] : cnt) {
        int c = cc.size();
        ans += c * (c - 1) / 2;
    }
    mint base = 29;
    repp(i, 1, 300'000) {
        map<pair<int, char>, set<int>> ncnt;
        for (auto [p, st] : cnt) {
            auto [s, c] = p;
            for (auto idx : st) {
                if (S[idx].size() <= i) continue;
                mint h = mint(s) * base + (c - 'a');
                ncnt[{h.val(), S[idx][i]}].insert(idx);
            }
        }
        cnt.clear();
        for (auto [p, a] : ncnt) {
            if (a.size() < 2) continue;
            cnt[p] = a;
        }
        for (auto [_, cc] : cnt) {
            int c = cc.size();
            ans += c * (c - 1) / 2;
        }
    }

    cout << ans << endl;
}
