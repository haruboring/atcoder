#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;
    map<char, vector<int>> map;
    rep(i, 3) {
        map[S[i]].push_back(1);
    }
    rep(i, 3) {
        if (map[S[i]].size() == 1) {
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}