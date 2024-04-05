#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

using mint = atcoder::modint998244353;
signed main() {
    int N;
    cin >> N;

    map<int, int> mp;
    int cN = N;
    while (cN % 2 == 0) {
        mp[2]++;
        cN /= 2;
    }
    while (cN % 3 == 0) {
        mp[3]++;
        cN /= 3;
    }
    while (cN % 5 == 0) {
        mp[5]++;
        cN /= 5;
    }

    if (cN != 1) {
        cout << 0 << endl;
        return 0;
    }

    mint ans = 0;
    for (int cnt4 = 0; cnt4 < 50; cnt4++) {
        for (int cnt6 = 0; cnt6 < 50; cnt6++) {
            int cnt2 = mp[2] - 2 * cnt4 - cnt6;
            int cnt3 = mp[3] - cnt6;
            int cnt5 = mp[5];
            if (cnt2 < 0 || cnt3 < 0) continue;

            int cnt = cnt2 + cnt3 + cnt4 + cnt5 + cnt6;
            mint kumi = 1;
            rep(i, cnt) {
                kumi *= i + 1;
            }
            rep(i, cnt2) {
                kumi *= mint(i + 1).inv();
            }
            rep(i, cnt3) {
                kumi *= mint(i + 1).inv();
            }
            rep(i, cnt4) {
                kumi *= mint(i + 1).inv();
            }
            rep(i, cnt5) {
                kumi *= mint(i + 1).inv();
            }
            rep(i, cnt6) {
                kumi *= mint(i + 1).inv();
            }
            ans += kumi * mint(5).inv().pow(cnt);
        }
    }

    cout << ans.val() << endl;
}
