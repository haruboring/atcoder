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
    string S;
    cin >> S;
    vector<int> l(Q), r(Q);
    rep(i, Q) cin >> l[i] >> r[i];

    vector<int> wa(N);
    rep(i, N-1){
        if (S[i+1] == S[i]) wa[i+1] = wa[i] + 1;
        else wa[i+1] = wa[i];
    }

    rep(i, Q){
        cout << wa[r[i]-1] - wa[l[i]-1] << endl;
    }
}