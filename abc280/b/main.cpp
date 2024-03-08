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
    vector<int> S(N);
    rep(i, N) {
        cin >> S[i];
    }
    vector<int> A(0);
    A.push_back(S[0]);
    rep(i, N - 1) {
        A.push_back(S[i+1]-S[i]);

    }
    rep(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
}