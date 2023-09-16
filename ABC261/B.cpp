#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<string> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    bool correct = true;
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            if (A[i][j] == 'D' && A[j][i] == 'D') {
                continue;
            } else if (A[i][j] == 'W' && A[j][i] == 'L') {
                continue;
            } else if (A[i][j] == 'L' && A[j][i] == 'W') {
                continue;
            } else {
                correct = false;
            }
        }
    }
    if (correct) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }
}