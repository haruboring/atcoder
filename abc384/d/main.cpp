#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int sum = 0;
    rep(i, N) sum += A[i];

    S = S % sum;

    vector<int> B(2 * N);
    rep(i, N) B[i] = A[i], B[i + N] = A[i];
    rep(i, 2 * N - 1) B[i + 1] += B[i];
    set<int> st;
    rep(i, 2 * N) st.insert(B[i]);

    while (!st.empty()) {
        int x = *st.begin();
        if (st.count(x + S)) {
            cout << "Yes" << endl;
            return 0;
        }
        st.erase(x);
    }

    cout << "No" << endl;
}
