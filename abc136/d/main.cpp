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

    int N = S.size();
    vector<int> L, R;
    rep(i, N) {
        if (S[i] == 'L') {
            L.push_back(i);
        } else {
            R.push_back(i);
        }
    }

    vector<int> A(N);
    rep(i, N) {
        if (S[i] == 'L') {
            int idx = lower_bound(all(R), i) - R.begin();
            int r = R[idx - 1];
            if ((r - i) % 2) r++;
            // debug(r);
            A[r]++;
        } else {
            int idx = lower_bound(all(L), i) - L.begin();
            int l = L[idx];
            if ((l - i) % 2) l--;
            // debug(l);
            A[l]++;
        }
    }

    rep(i, N) cout << A[i] << " ";
    cout << endl;
}
