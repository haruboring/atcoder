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
    vector<ll> A(N);
    rep(i, Q) {
        int flag, x;
        cin >> flag >> x;
        if (flag == 3) {
            if (A[x - 1] < 2) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        } else {
            A[x - 1] += flag;
        }
    }
}