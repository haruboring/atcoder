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
    vector<int> A(N), ata(N + 1), haz(N + 1);
    rep(i, N) {
        cin >> A[i];
        if (A[i] == 1) {
            ata[i + 1] = ata[i] + 1;
            haz[i + 1] = haz[i];
        } else {
            ata[i + 1] = ata[i];
            haz[i + 1] = haz[i] + 1;
        }
    }
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
    }
    rep(i, Q) {
        if ((ata[R[i]] - ata[L[i] - 1]) > haz[R[i]] - haz[L[i] - 1]) {
            cout << "win" << endl;
        } else if ((ata[R[i]] - ata[L[i] - 1]) == haz[R[i]] - haz[L[i] - 1]) {
            cout << "draw" << endl;
        } else {
            cout << "lose" << endl;
        }
    }
}