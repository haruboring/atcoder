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
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N) X[i]--;

    map<vector<int>, int> mp;
    vector<vector<int>> tmp;

    rep(i, K) {
        if (mp.count(A)) {
            int s = mp[A];
            A = tmp[s + (K - s) % (i - s)];
            break;
        }
        mp[A] = i;
        tmp.push_back(A);

        vector<int> nextA(N);
        rep(j, N) {
            nextA[j] = A[X[j]];
        }
        A = nextA;
    }

    rep(i, N) cout << A[i] << " ";
    cout << endl;
}
