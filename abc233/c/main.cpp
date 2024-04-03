#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> L(N);
    vector<vector<int>> A(N, vector<int>(0));
    rep(i, N) {
        cin >> L[i];
        rep(j, L[i]) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    multiset<int> s;
    s.insert(X);
    rep(i, N) {
        debug(s.size());
        multiset<int> st;
        rep(j, L[i]) {
            for (auto a : s) {
                if (a % A[i][j] == 0) st.insert(a / A[i][j]);
            }
        }

        s = st;
    }

    cout << s.count(1) << endl;
}
