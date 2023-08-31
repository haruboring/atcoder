#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> P[i][j];

    int ans = -1;

    for (int i = 0; i < (1 << H); i++) {
        bitset<8> bs(i);
        map<int, int> mp;
        int row_cnt = 0;
        for (int j = 0; j < H; j++) {
            if (bs[j]) row_cnt++;
        }

        for (int j = 0; j < W; j++) {
            set<int> st;
            for (int k = 0; k < H; k++) {
                if (bs[k]) st.insert(P[k][j]);
            }
            if (st.size() == 1) mp[*st.begin()]++;
        }
        for (auto p : mp) ans = max(ans, p.second * row_cnt);
    }

    cout << ans << endl;
}
