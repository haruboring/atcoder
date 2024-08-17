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

    int H = -1;
    rep(i, N) H = max(H, (int)S[i].size());
    vector<vector<char>> T(H, vector<char>(N, '*'));
    rep(i, N) {
        rep(j, S[i].size()){
            T[]
        }
    }
}
