#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<int> par(200000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }

    init(N);
    vector<vector<ll>> CAB(0, vector<ll>(0));
    ll earn = 0;
    rep(i, M) {
        if (C[i] <= 0) {
            unite(A[i], B[i]);
        } else {
            CAB.push_back({C[i], A[i], B[i]});
            earn += C[i];
        }
    }
    sort(all(CAB));
    for (auto cab : CAB) {
        ll c = cab[0], a = cab[1], b = cab[2];
        if (root(a) != root(b)) {
            unite(a, b);
            earn -= c;
        }
    }
    cout << earn << endl;
}