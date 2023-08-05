#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<double> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    double av = 0, cnt_contain_bug_program = 0;
    rep(i, N) {
        av += A[i];
        if (A[i] != 0) {
            cnt_contain_bug_program++;
        }
    }
    av /= cnt_contain_bug_program;
    cout << ceil(av) << endl;
}