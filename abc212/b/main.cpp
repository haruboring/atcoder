#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    vector<int> A(4);
    rep(i, 4) A[i] = S[i] - '0';

    set<int> s;
    rep(i, 4) s.insert(A[i]);
    if (s.size() == 1) {
        cout << "Weak" << endl;
        return 0;
    }

    rep(i, 3) {
        if (S[i + 1] != S[i] + 1 + i) {
            cout << "Strong" << endl;
            return 0;
        }
    }

    cout << "Weak" << endl;
}
