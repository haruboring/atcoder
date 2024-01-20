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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    int sumA = 0, sumB = 0;
    rep(i, N) {
        sumA += A[i];
        sumB += B[i];
    }

    if (sumA > sumB)
        cout << "Takahashi" << endl;
    else if (sumA < sumB)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;
}
