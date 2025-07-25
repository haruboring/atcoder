#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    rep(i, M) X[i]--, Y[i]--;
    map<int, int> m;
    rep(i, N) m[i] = 1;
    set<int> s;
    s.insert(0);

    rep(i, M) {
        int x = X[i], y = Y[i];
        m[x]--;
        m[y]++;
        if (s.count(x)) {
            s.insert(y);
            if (m[x] == 0) s.erase(x);
        }
    }

    cout << s.size() << endl;
}
