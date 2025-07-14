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

    set<int> ss;
    vector<int> chg = {3, 5, 7};
    rep(i, pow(3, 9)) {
        int a = 0, k = 1, ci = i;
        set<int> s;
        rep(_, 9) {
            int b = ci % 3;
            ci /= 3;
            s.insert(b);
            a = a + k * chg[b];
            k *= 10;
            // debug(a);
            if (s.size() != 3) continue;
            if (a <= N) {
                ss.insert(a);
                // debug(a);
            }
            // debug(a);
        }
    }

    cout << ss.size() << endl;
}
