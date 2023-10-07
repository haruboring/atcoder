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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    map<int, int> P;
    rep(i, N) {
        P[i + 1] = 0;
    }

    rep(i, N) {
        rep(j, N) {
            if (S[i][j] == 'o') {
                P[i + 1]++;
            }
            if (S[i][j] == 'x') {
                P[j + 1]++;
            }
        }
    }

    vector<pair<int, int>> v;
    for (auto p : P) {
        v.push_back(make_pair(p.second, -p.first));
    }

    sort(all(v));
    reverse(all(v));

    rep(i, N) {
        cout << -v[i].second << " ";
    }
    cout << endl;
}