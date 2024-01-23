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

    multiset<int> m;
    m.insert(A[0]);
    repp(i, 1, N) {
        int minimum = *m.begin();
        if (A[i] <= minimum) {
            m.insert(A[i]);
        } else {
            auto itr = m.lower_bound(A[i]);
            itr--;
            m.erase(itr);
            m.insert(A[i]);
        }
    }

    cout << m.size() << endl;
}
