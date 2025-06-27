#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int cnt = 0, Cc = 0;
    while (A > Cc * D) {
        A += B;
        Cc += C;
        cnt++;

        if (cnt > 1e6) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;
}
