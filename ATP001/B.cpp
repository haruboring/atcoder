#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<int> par(100000 + 10);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(Q), A(Q), B(Q);
    rep(i, Q) cin >> P[i] >> A[i] >> B[i];

    init(N);
    rep(i, Q) {
        if (P[i] == 0) {
            unite(A[i], B[i]);
        } else {
            if (root(A[i]) == root(B[i])) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}