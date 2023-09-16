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
    rep(i, N) {
        cin >> A[i];
    }
    set<int> contain;
    vector<int> not_duplicated(0), ans(N);
    rep(i, N) {
        if (contain.count(A[i])) {
            continue;
        } else {
            contain.insert(A[i]);
            not_duplicated.push_back(A[i]);
        }
    }
    sort(all(not_duplicated));
    rep(i, N) {
        int pos = lower_bound(all(not_duplicated), A[i]) - not_duplicated.begin();
        cout << pos + 1 << " ";
    }
    cout << endl;
}