#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int f(int i, vector<int> A) {
    if (i == -1) return 0;
    vector<int> S, T;
    rep(j, A.size()) {
        if ((A[j] >> i) & 1)
            S.push_back(A[j]);
        else
            T.push_back(A[j]);
    }

    if (S.size() == 0) return f(i - 1, T);
    if (T.size() == 0) return f(i - 1, S);

    return min(f(i - 1, S), f(i - 1, T)) | (1 << i);
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    cout << f(30, A) << endl;
}
