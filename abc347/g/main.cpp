#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    // cout << 200 << " " << 200 << endl;
    // rep(i, 200) {
    //     rep(j, 200) {
    //         cout << '.';
    //     }
    //     cout << endl;
    // }
    int N = 300;
    cout << N << endl;
    rep(i, N) {
        cout << (i / 200) + 1 << " " << (i % 200) + 1 << " " << 400 << endl;
    }
}
