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
    vector<char> c = {'A', 'B', 'C', 'D', 'E', 'F'};
    map<char, int> m;
    rep(i, S.size()) {
        m[S[i]]++;
    }
    rep(i, c.size()) {
        if (i != c.size() - 1) {
            cout << m[c[i]] << " ";
        } else {
            cout << m[c[i]];
        }
    }
    cout << endl;
}