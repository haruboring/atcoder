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
    int correct_sum = 0;
    rep(i, 9) {
        rep(j, 9) {
            correct_sum += (i + 1) * (j + 1);
        }
    }
    int dif = correct_sum - N;
    rep(i, 9) {
        rep(j, 9) {
            if ((i + 1) * (j + 1) == dif) {
                cout << (i + 1) << " x " << (j + 1) << endl;
            }
        }
    }
}