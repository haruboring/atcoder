#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int sum = 0;
    rep(i, N) {
        if (sum + H[i] > M) {
            cout << i << endl;
            return 0;
        }
        sum += H[i];
    }

    cout << N << endl;
}
