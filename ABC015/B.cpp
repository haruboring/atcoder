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