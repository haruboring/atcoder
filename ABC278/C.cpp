#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q), A(Q), B(Q);
    rep(i, Q) {
        cin >> T[i] >> A[i] >> B[i];
    }
    map<pair<int, int>, int> f;
    rep(i, Q) {
        if (T[i] == 1) {
            f[make_pair(A[i], B[i])] = 1;
        } else if (T[i] == 2) {
            f[make_pair(A[i], B[i])] = 0;
        } else {
            if (f[make_pair(A[i], B[i])] == 1 && f[make_pair(B[i], A[i])] == 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}