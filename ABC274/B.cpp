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
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> C[i][j];
        }
    }
    bool b = false;
    rep(i, W) {
        int ans = 0;
        rep(j, H) {
            if (C[j][i] == '#') {
                ans++;
            }
        }
        if(b){
            cout << " " << ans;
        }
        else{
            cout << ans;
            b = true;
        }
    }
    cout << endl;
}