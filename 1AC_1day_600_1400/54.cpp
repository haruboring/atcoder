#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int C;
    cin >> C;
    vector<int> N(C), M(C), L(C);
    rep(i, C) cin >> N[i] >> M[i] >> L[i];

    vector<vector<int>> NML(C, vector<int>(3));
    rep(i, C) {
        NML[i][0] = N[i];
        NML[i][1] = M[i];
        NML[i][2] = L[i];
        sort(all(NML[i]));
    }
    int tate = -1, yoko = -1, takasa = -1;
    rep(i, C) {
        tate = max(tate, NML[i][0]);
        yoko = max(yoko, NML[i][1]);
        takasa = max(takasa, NML[i][2]);
    }
    cout << tate * yoko * takasa << endl;
}