#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> lx(N), ly(N), rx(N), ry(N);
    rep(i, N) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];

    vector<vector<int>> p(1000 + 100, vector<int>(1000 + 100, 0));
    rep(i, N) {
        p[lx[i]][ly[i]]++;
        p[rx[i]][ry[i]]++;
        p[rx[i]][ly[i]]--;
        p[lx[i]][ry[i]]--;
    }

    vector<vector<int>> s(1000 + 100, vector<int>(1000 + 100, 0));
    rep(i, 1000 + 1) {
        rep(j, 1000 + 1) {
            s[j][i] = p[j][i];
            if (j != 0) s[j][i] += s[j - 1][i];
        }
    }

    vector<vector<int>> t(1000 + 100, vector<int>(1000 + 100, 0));
    rep(i, 1000 + 1) {
        rep(j, 1000 + 1) {
            t[i][j] = s[i][j];
            if (j != 0) t[i][j] += t[i][j - 1];
        }
    }

    vector<int> ans(N + 1, 0);
    rep(i, 1000 + 1) {
        rep(j, 1000 + 1) {
            ans[t[i][j]]++;
        }
    }

    repp(i, 1, N + 1) {
        cout << ans[i] << endl;
    }
}