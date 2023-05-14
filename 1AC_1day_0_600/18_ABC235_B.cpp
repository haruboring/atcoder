#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int pos;
    for (pos = 0; pos < N; pos++) {
        if (H[pos + 1] <= H[pos]) {
            break;
        }
    }
    cout << H[pos] << endl;
}