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

    multiset<int> A;
    rep(i, N) {
        int a;
        cin >> a;
        A.insert(a);
    }
    vector<int> B(M);
    rep(i, M) cin >> B[i];

    rep(i, M) {
        if (A.count(B[i])) {
            A.erase(A.find(B[i]));
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}