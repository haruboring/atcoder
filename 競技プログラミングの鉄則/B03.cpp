#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define cY cout << "Yes" << endl
#define cN cout << "No" << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N - 2) {
        repp(j, i + 1, N - 1) {
            repp(k, j + 1, N) {
                if (A[i] + A[j] + A[k] == 1000) {
                    cY;
                    return 0;
                }
            }
        }
    }
    cN;
}