#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, a, b, K;
    cin >> N >> a >> b >> K;
    vector<int> P(K);
    rep(i, K) {
        cin >> P[i];
    }
    set<int> s = {a, b};
    rep(i, K) {
        if (s.count(P[i])) {
            cout << "NO" << endl;
            return 0;
        }
        s.insert(P[i]);
    }
    cout << "YES" << endl;
}