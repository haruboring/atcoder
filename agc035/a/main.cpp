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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<bitset<40>> B(N);
    rep(i, N) B[i] = bitset<40>(A[i]);

    vector<int> C(40);
    rep(i, 40) {
        rep(j, N) {
            if (B[j][i]) C[i]++;
        }
    }

    rep(i, 40) {
        int z = N - C[i];
        int o = C[i];
        if (o == 0) continue;

        // cout << i << endl;
        // cout << o << " " << z << endl;

        z--;

        int tmp = min(o / 4, z / 2);
        z -= 2 * tmp;
        o -= 4 * tmp;

        if (o == 0 && z == 1) continue;
        if (o == 1 && z == 0) continue;
        if (o == 2 && z == 0) continue;
        if (o == 4 && z == 1) continue;

        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
