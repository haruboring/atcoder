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
    int m = 10000;
    rep(i, S.size() - 2) {
        string ss = "";
        repp(j, i, i + 3) {
            ss += S[j];
        }
        m = min(m, abs(stoi(ss) - 753));
    }
    cout << m << endl;
}