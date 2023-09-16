#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) {
        cin >> S[i];
    }
    int ans = 0;
    rep(i, H) {
        rep(j, W - 1) {
            if (S[i][j] == S[i][j + 1] && S[i][j] == 'T') {
                S[i][j] = 'P';
                S[i][j + 1] = 'C';
                ans++;
            }
        }
    }
    rep(i, H) {
        cout << S[i] << endl;
    }
}