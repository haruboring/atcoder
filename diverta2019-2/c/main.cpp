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

    int c = 0;
    rep(i, N) if (A[i] < 0) c++;
    c = max(1LL, c);

    multiset<int> s;
    rep(i, N) s.insert(A[i]);
    vector<int> X(0), Y(0);
    rep(i, N - 1) {
        int x, y;
        if (i < N - c - 1) {
            x = *s.begin();
            y = *s.rbegin();
        } else {
            x = *s.rbegin();
            y = *s.begin();
        }

        s.erase(s.find(x));
        s.erase(s.find(y));
        X.push_back(x);
        Y.push_back(y);
        s.insert(x - y);
    }
    int M = *s.begin();
    cout << M << endl;
    rep(i, N - 1) cout << X[i] << " " << Y[i] << endl;
}
