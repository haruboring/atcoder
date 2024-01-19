#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using namespace atcoder;
using mint = modint998244353;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int M = 2e5 + 100;
    fenwick_tree<mint> fw1(M + 1), fw2(M + 1);
    mint sum = 0;
    rep(i, N) {
        mint d = fw1.sum(0, A[i] + 1) * mint(A[i]) + fw2.sum(A[i] + 1, M + 1);
        sum += mint(2) * d + mint(A[i]);
        fw1.add(A[i], mint(1));
        fw2.add(A[i], mint(A[i]));
        cout << (sum * (mint(i + 1).inv().pow(2))).val() << endl;
    }
}
