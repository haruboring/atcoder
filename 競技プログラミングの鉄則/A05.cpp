#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    repp(i, 1, N + 1) {
        repp(j, 1, N + 1) {
            if (0 < (K - (i + j)) && (K - (i + j)) < N + 1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}