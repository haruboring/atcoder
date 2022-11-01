#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N + 1));
    rep(i, N) {
        rep(j, i + 1) {
            if (j == 0 || j == i) {
                A[i][j] = 1;
            } else {
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
            }
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}