#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int N;
    cin >> N;

    map<int, int> m;
    for (int i = 1; i <= N; i++) {
        int t = i;
        for (int j = 2; j * j <= i; j++) {
            while (t % j == 0) {
                m[j]++;
                t /= j;
            }
        }
        if (t != 1) m[t]++;
    }

    mint cnt = 1;
    for (auto [k, c] : m) cnt *= c + 1;

    cout << cnt.val() << endl;
}
