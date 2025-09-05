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

    bool is_ord = true;
    vector<int> A(N);
    rep(i, N) A[i] = i + 1;
    rep(_, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            if (!is_ord) x = N - 1 - x;
            A[x] = y;
        } else if (f == 2) {
            is_ord = !is_ord;
        } else {
            int x;
            cin >> x;
            x--;
            if (!is_ord) x = N - 1 - x;
            cout << A[x] << endl;
        }
    }
}
