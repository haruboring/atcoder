#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    vector<vector<int>> ans(N, vector<int>(N, 0));
    int mi = 1, ma = N * N;
    rep(i, N) {
        rep(j, N) {
            if (i % 2 == 0) {
                ans[i][j] = mi;
                mi++;
            } else {
                ans[i][j] = ma;
                ma--;
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            cout << setw(3) << ans[i][j] << " ";
        }
        cout << endl;
    }
}