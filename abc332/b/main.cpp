#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K, G, M;
    cin >> K >> G >> M;

    int g = 0, m = 0;
    rep(_, K) {
        if (g == G) {
            g = 0;
        } else if (m == 0) {
            m = M;
        } else {
            int pour = min(G, g + m) - g;
            g += pour;
            m -= pour;
        }
    }

    cout << g << " " << m << endl;
}
