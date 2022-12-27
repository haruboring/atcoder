#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, S, T, W;
    cin >> N >> S >> T >> W;
    vector<int> A(N - 1);
    rep(i, N - 1) {
        cin >> A[i];
    }
    int cnt = 0;
    if (S <= W && W <= T) {
        cnt++;
    }
    rep(i, N - 1) {
        W += A[i];
        if (S <= W && W <= T) {
            cnt++;
        }
    }
    cout << cnt << endl;
}