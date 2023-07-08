#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    rep(i, N) cin >> A[i];

    string B1 = A[1][0] + A[0].substr(0, N - 1);
    cout << B1 << endl;
    rep(i, N - 2) {
        cout << A[i + 2][0] + A[i + 1].substr(1, N - 2) + A[i][N - 1] << endl;
    }
    string BN = A[N - 1].substr(1, N - 1) + A[N - 2][N - 1];
    cout << BN << endl;
}