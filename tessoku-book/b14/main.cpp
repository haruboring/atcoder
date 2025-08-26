#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    set<int> s;
    for (int i = 0; i < 1 << (N / 2); i++) {
        bitset<30> b(i);
        int t = 0;
        rep(j, N / 2) if (b.test(j)) t += A[j];
        s.insert(t);
    }

    for (int i = 0; i < 1 << (N - (N / 2)); i++) {
        bitset<30> b(i);
        int t = 0;
        rep(j, N - (N / 2)) if (b.test(j)) t += A[N - 1 - j];
        if (s.count(K - t)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
