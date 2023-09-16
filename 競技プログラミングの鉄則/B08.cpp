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
    vector<int> X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
    }
    int Q;
    cin >> Q;
    vector<map<char, int>> ad(Q);
    rep(i, Q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ad[i]['a'] = a;
        ad[i]['b'] = b;
        ad[i]['c'] = c;
        ad[i]['d'] = d;
    }
    vector<vector<int>> place(1500 + 1, vector<int>(1500 + 1));
    rep(i, N) {
        place[X[i]][Y[i]]++;
    }
    rep(i, 1500 + 1) {
        int cnt = 0;
        rep(j, 1500 + 1) {
            cnt += place[i][j];
            place[i][j] = cnt;
        }
    }
    rep(i, 1500 + 1) {
        int cnt = 0;
        rep(j, 1500 + 1) {
            cnt += place[j][i];
            place[j][i] = cnt;
        }
    }
    rep(i, Q) {
        cout << place[ad[i]['c']][ad[i]['d']] - place[ad[i]['c']][ad[i]['b'] - 1] - place[ad[i]['a'] - 1][ad[i]['d']] + place[ad[i]['a'] - 1][ad[i]['b'] - 1] << endl;
    }
}