#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    set<int> teeth;
    rep(i, N) teeth.insert(i + 1);
    rep(_, Q) {
        int T;
        cin >> T;
        if (teeth.count(T)) {
            teeth.erase(T);
        } else {
            teeth.insert(T);
        }
    }

    cout << teeth.size() << endl;
}
