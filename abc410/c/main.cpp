#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    rep(i, N) A[i] = i + 1;
    int rot = 0;

    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            A[(p + rot) % N] = x;
        } else if (f == 2) {
            int p;
            cin >> p;
            p--;
            cout << A[(p + rot) % N] << endl;
        } else {
            int k;
            cin >> k;
            rot += k;
        }
    }
}
