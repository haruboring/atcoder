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

    vector<int> v;
    rep(i, S.size()) {
        if (S[i] == '#') v.push_back(i + 1);
    }

    rep(i, v.size() / 2) {
        cout << v[2 * i] << "," << v[2 * i + 1] << endl;
    }
}
