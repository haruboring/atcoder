#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    rep(i, H) {
        rep(j, W) {
            if ((i < B && j < A) || (i >= B && j >= A)) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}