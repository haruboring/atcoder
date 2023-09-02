#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> al(0);
    rep(i, N) {
        rep(j, A[i]) {
            al.push_back(i + 1);
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (i % 2 == 0) {
                cout << al[i * W + j] << " ";
            } else {
                cout << al[i * W + (W - j - 1)] << " ";
            }
        }
        cout << endl;
    }
}