#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> I(Q), X(Q);
    rep(i, Q) cin >> I[i] >> X[i];

    set<int> S;
    rep(i, 4e5 + 100) S.insert(i);
    map<int, int> mp;
    rep(i, N) {
        mp[A[i]]++;
        if (S.count(A[i])) S.erase(A[i]);
    }
    rep(i, Q) {
        int erase = A[I[i] - 1];
        mp[erase]--;
        if (mp[erase] == 0) S.insert(erase);
        A[I[i] - 1] = X[i];
        mp[X[i]]++;
        if (S.count(X[i])) S.erase(X[i]);

        cout << *S.begin() << endl;
    }
}
