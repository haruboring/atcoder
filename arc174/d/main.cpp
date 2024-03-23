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
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    set<string> syy;

    for (auto t : T) {
        int cnt = 0;
        repp(x, 1, t + 1) {
            int y = sqrt(x);
            string sy = to_string(y);
            string sx = to_string(x);

            if (sy == sx.substr(0, sy.size())) {
                cnt++;
                syy.insert(sy);
                // cout << "sx: " << sx << ", sy: " << sy << endl;
            }
        }

        cout << cnt << endl;

        for (auto aa : syy) {
            cout << aa << " ";
        }
        cout << endl;
    }
}
