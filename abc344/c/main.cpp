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
    int M;
    cin >> M;
    vector<int> B(M);
    rep(i, M) cin >> B[i];
    int L;
    cin >> L;
    vector<int> C(L);
    rep(i, L) cin >> C[i];
    int Q;
    cin >> Q;
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    set<int> s;
    rep(i, N) {
        rep(j, M) {
            rep(k, L) {
                s.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    rep(i, Q) {
        if (s.count(X[i]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
