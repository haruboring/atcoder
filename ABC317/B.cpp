#include "atcoder/all"
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
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);

    sort(all(A));

    rep(i, N - 1) {
        if (A[i + 1] != A[i] + 1) {
            cout << A[i] + 1 << endl;
            return 0;
        }
    }
}