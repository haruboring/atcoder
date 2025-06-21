#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(500'000 + 100);

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
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(Q);
    rep(i, Q) cin >> A[i];

    vector<int> B(N + 2, 1);
    int cnt = 0;
    rep(i, Q) {
        int x = A[i];
        B[x] *= -1;
        if (B[x - 1] == 1 && B[x] == 1 && B[x + 1] == 1) {
            cnt--;
        } else if (B[x - 1] == -1 && B[x] == 1 && B[x + 1] == -1) {
            cnt++;
        } else if (B[x - 1] == 1 && B[x] == -1 && B[x + 1] == 1) {
            cnt++;
        } else if (B[x - 1] == -1 && B[x] == -1 && B[x + 1] == -1) {
            cnt--;
        }
        cout << cnt << endl;
    }
}