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

    int pre_s = 1;
    vector<vector<char>> pre = {{'#'}};
    rep(i, N) {
        int next_s = pre_s * 3;
        vector<vector<char>> next(next_s, vector<char>(next_s, '.'));
        rep(j, next_s) {
            rep(k, next_s) {
                if (j / pre_s == 1 && k / pre_s == 1) continue;
                next[j][k] = pre[j % pre_s][k % pre_s];
            }
        }

        pre = next;
        pre_s = next_s;
    }

    rep(i, pre_s) {
        rep(j, pre_s) {
            cout << pre[i][j];
        }
        cout << endl;
    }
}
