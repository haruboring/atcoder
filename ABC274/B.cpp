#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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