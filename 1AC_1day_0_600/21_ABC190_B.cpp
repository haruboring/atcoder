#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, S, D;
    cin >> N >> S >> D;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) {
        if (X[i] < S && Y[i] > D) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}