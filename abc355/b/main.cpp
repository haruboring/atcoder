#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    set<int> s;
    rep(i, N) s.insert(A[i]);

    vector<int> AB = A;
    rep(i, M) AB.push_back(B[i]);

    sort(all(AB));

    bool b = false;
    rep(i, N + M) {
        if (s.count(AB[i])) {
            if (b) {
                cout << "Yes" << endl;
                return 0;
            }
            b = true;
        } else {
            b = false;
        }
    }

    cout << "No" << endl;
}
