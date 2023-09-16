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
    vector<vector<int>> S(N, vector<int>(0));
    S[0].push_back(1);
    rep(i, N - 1) {
        rep(j, S[i].size()){
            S[i+1].push_back(S[i][j]);
        }
        S[i+1].push_back(i+2);
        rep(j, S[i].size()){
            S[i+1].push_back(S[i][j]);
        }
    }
    rep(i, S[N - 1].size()) {
        cout << S[N - 1][i] << " ";
    }
    cout << endl;
}