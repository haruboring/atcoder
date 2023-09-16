#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int dis_A = abs(A[0] - x), dis_B = abs(y);
    // A[1] ~の値でdis_A, dis_Bを作れるかどうかで判定
    vector<int> A_x(N - 1 / 2), A_y(N / 2);
    repp(i, 1, N) {
        if (i % 2 == 0) {
            A_x[i / 2] = A[i];
        } else {
            A_y[i / 2] = A[i];
        }
    }
    sort(all(A_x));
    reverse(all(A_x));
    sort(all(A_y));
    reverse(all(A_y));

    int base_x = 0;
    rep(i, A_x.size()) {
        if (base_x >= dis_A) {
            base_x -= A_x[i];
        } else {
            base_x += A_x[i];
        }
    }
    int base_y = 0;
    rep(i, A_y.size()) {
        if (base_y >= dis_B) {
            base_y -= A_y[i];
        } else {
            base_y += A_y[i];
        }
    }
    if (base_x == dis_A && base_y == dis_B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}