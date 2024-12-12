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
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int T = 0;
    rep(i, N) {
        T += 3 * (H[i] / 5);
        int rest_h = H[i] % 5;
        while (rest_h > 0) {
            T++;
            if (T % 3 == 0) {
                rest_h -= 3;
            } else {
                rest_h -= 1;
            }
        }
    }

    cout << T << endl;
}
