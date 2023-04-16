#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N)), Acopy(N, vector<int>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> A[i][j];
        }
    }
    rep(i, N) {
        rep(j, N) {
            cin >> B[i][j];
        }
    }
    rep(k, 10) {
        Acopy = A;
        rep(i, N) {
            rep(j, N) {
                A[N - j - 1][i] = Acopy[i][j];
            }
        }
        bool a = true;
        rep(i, N) {
            rep(j, N) {
                if (A[i][j] == 1) {
                    if (B[i][j] == 0) {
                        a = false;
                    }
                }
            }
        }
        if (a) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}