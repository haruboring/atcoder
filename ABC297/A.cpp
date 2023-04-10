#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> T(N);
    rep(i, N) {
        cin >> T[i];
    }
    rep(i, N - 1) {
        if (T[i + 1] - T[i] <= D) {
            cout << T[i + 1] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}