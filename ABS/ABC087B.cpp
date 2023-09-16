#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int cnt = 0;
    rep(i, A + 1) {
        rep(j, B + 1) {
            rep(k, C + 1) {
                if (i * 500 + j * 100 + k * 50 == X) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}