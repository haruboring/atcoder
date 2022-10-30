#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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