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
    int A, B_;
    cin >> A >> B_;

    if (B_ == 0) {
        cout << 0 << endl;
        return 0;
    }

    mint B = B_;

    bool even = true;

    map<int, int> ae;
    int cA = A;
    for (int i = 2; i * i <= A; i++) {
        while (cA % i == 0) {
            ae[i]++;
            cA /= i;
        }
        if (ae[i] % 2) even = false;
        // debug(ae[i]);
    }
    if (cA != 1) {
        ae[cA]++;
        if (ae[cA] % 2) even = false;
    }

    mint cnt = 1;
    for (auto [k, v_] : ae) {
        mint v = v_;
        cnt *= v * B + 1;
    }
    cnt *= B;

    if (even && (B_ % 2)) cnt--;

    cnt /= 2;

    cout << cnt.val() << endl;
}
